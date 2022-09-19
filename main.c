#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int numTotalP = 0;
//int numTotalV = 0;

//Structures Section
struct produit{
    //Members
    char code[14], nom[30], time[30];
    int quantite;
    float prix;
};
struct produit p[100];

struct produitVendu{
    char code[14], time[30];
    int quantite;
    struct produit p;
};
//OperationProduits
void OperationProduits(){
    int N,OP;
    do{
        printf("Choisir une operation:\n");
        printf("1 - Ajouter Un Produit\n");
        printf("2 - Rechercher Un Produit\n");
        printf("3 - Supprimer Un Produit\n");
        printf("4 - Afficher Les Produits\n");
        printf("5 - Trier Un Produit\n");
        printf("6 - Acheter le Produit\n");
        printf("7 - Quitter De Programme\n");
        scanf("%d",&OP);


        switch(OP){
            case 1:
                printf("Combien de produits souhaitez-vous saisir ?: ");
                scanf("%d",&N);
                ajouterProduits(N);
                break;
            case 2:
                rechercheProduits();
                break;
            case 3:
                break;
            case 4:
                afficherProduit(N);
                break;
            case 5:
                operationTrier();
                break;
            case 6:
                acheterProduit();
                break;
            case 7:
                printf("By by\n");
                break;

        }

    }while(OP != 7);

}
//ajouterProduits
void ajouterProduits(int N){
    //ajouter
    for(int i=numTotalP; i<N+numTotalP; i++){
        printf("\nDonnez Le Code Produit: ");
        scanf("%s",p[i].code);
        printf("Donnez Le Nom Produit: ");
        scanf("%s",p[i].nom); //Because Ineed Space
        printf("Donnez Le Quantitie Produit: ");
        scanf("%d",&p[i].quantite);
        printf("Donnez Le Prix Produit: ");
        scanf("%f",&p[i].prix);
        p[i].prix += 0.15 * p[i].prix; //TTC 15%
    }
    numTotalP += N;
}
//afficherProduit
void afficherProduit(){
    //afficher
    printf("\n\t\tPorduit\t\tCode\tNom\tQuantitie\tPrix\t\n");
    printf("\t\t--------------------------------------------------------------------------\n");
    for(int j=0; j<numTotalP; j++){
        printf("\t\t%d\t\t%s\t%s\t%d\t\t%.2fDH\n",j+1,p[j].code,p[j].nom,p[j].quantite,p[j].prix);
    }
}
//Function l’ordre alphabétique croissant du nom.
void orderAlpha(){
    int i,j;
    struct produit X;
    for(i=0; i<numTotalP-1; i++){
        for(j=i+1; j<numTotalP; j++){
            if(strcmp(p[i].nom,p[j].nom) > 0){ //if p[i].nom > p[j].nom So strcmp return value positive
                X = p[i];
                p[i] = p[j];
                p[j]= X;
            }
        }
    }
}
//l’ordre décroissant du prix. //Triage par bulle
void orderPrix(){
    int i,j;
    struct produit X;
    for(i=0; i<numTotalP-1; i++){
        for(j=i+1; j<numTotalP; j++){
            if(p[i].prix < p[j].prix){
                X = p[i];
                p[i] = p[j];
                p[j]= X;
            }
        }
    }
}
//operationTrier
void operationTrier(){
    int op;
    do{
    printf("1 - L’ordre Alphabetique Croissant Du Nom:\n");
    printf("2 - L’ordre Decroissant Du Prix:\n");
    printf("3 - Back! Menu\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            orderAlpha();
            afficherProduit();
            break;
        case 2:
            orderPrix();
            afficherProduit();
            break;
        case 3:
            system("cls");
            OperationProduits();
            break;
    }
    }while(op != 3);
}

//Function mettre à jour la quantité après avoir introduit le code produit
void acheterProduit(){
    int N,count,i;
    char c[14];
    float Newprix=0;
    time_t currentTime;
    struct produit pV[100];
    printf("Donnez Le Code Produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
       if(strcmp(c,p[i].code) == 0){ // c == code return value 0
            printf("Donnez le nombre de ce produit qui a vendue: ");
            scanf("%d",&N);
                if(N <= p[i].quantite){
                    Newprix = (p[i].prix * N) / (p[i].quantite);
                    p[i].prix -= Newprix;
                    p[i].quantite -= N;


                    //time Acheter
                    time(&currentTime);
                    strcpy(p[i].time , ctime(&currentTime));

                    //Afichage Acheter
                    printf("\n\t\tPorduit\t\tCode\tQuantitie\t\tDate Acheter\n");
                    printf("\t\t-------------------------------------------------------------------\n");
                    printf("\t\t%d\t\t%s\t%d\t\t%s\n",i+1,p[i].code,p[i].quantite,p[i].time);

                }else{
                    count = 1;
                }
       }else{
            count = 2;
       }
       if(count == 1) printf("La Quantite n'est pas suffisante\n");
       if(count == 2) printf("Le code N'existe pas dans la liste des produit\n");
    }

}

//Recherche les Produits
void rechercheProduits(){
    int i;
    char c[14];
    struct produit pSearch;
    printf("Entrez le code produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
        if(strcmp(c , p[i].code) == 0){
            strcpy(pSearch.code,p[i].code);
            strcpy(pSearch.nom,p[i].nom);
            pSearch.quantite=p[i].quantite;
            pSearch.prix=p[i].prix;

            //Affichage Recherche
            printf("\n\t\tCode\tNom\tQuantitie\tPrix\t\n");
            printf("\t\t--------------------------------------------------------------------------\n");
            printf("\t\t%s\t%s\t%d\t\t%.2fDH\n",pSearch.code,pSearch.nom,pSearch.quantite,pSearch.prix);
        }else{
            printf("Le code N'existe pas dans la liste des produit!");
        }
    }
}

////Function codeP
//void codeP(struct produit p[100], int numTotalP, char c){
//    int i;
//    printf("Donnez le code Produit: ");
//    scanf("%s",&c);
//    for(i=0; i<numTotalP; i++){
//        if(c == p[i].code){
//            printf("Code: %d\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
//            break;
//        }
//    }
//}
////Function quantiteP
//void quantiteP(struct produit p[100], int numTotalP, double q){
//    int i;
//    printf("Donnez la Quantite Produit: ");
//    scanf("%d",&q);
//    for(i=0; i<numTotalP; i++){
//        if(q == p[i].quantite){
//            printf("Code: %d\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
//            break;
//        }
//    }
//}
//Etat du stock


int main()
{

    OperationProduits(p);
    return 0;
}
