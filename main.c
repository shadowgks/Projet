#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Structures Section
struct produit{
    //Members
    char code[14], nom[30], time[30];
    int quantite;
    float prix;
};

int numTotalP = 0;
struct produit p[100];


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
                system("cls");
                printf("Combien de produits souhaitez-vous saisir ?: ");
                scanf("%d",&N);
                ajouterProduits(N);
                break;
            case 2:
                system("cls");
                OperationRechercheProduits();
                break;
            case 3:
                break;
            case 4:
                system("cls");
                afficherProduit(N);
                break;
            case 5:
                system("cls");
                operationTrier();
                break;
            case 6:
                system("cls");
                acheterProduit();
                break;
            case 7:
                printf("Au Revoire :)\n");
                break;
            default:
                system("cls");
                printf("Numero de Operation Pas Correct!!!\n");
        }

    }while(OP != 7);

}
//ajouterProduits
void ajouterProduits(int N){
    char c[14];
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
            system("cls");
            orderAlpha();
            afficherProduit();
            break;
        case 2:
            system("cls");
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
//    float Newprix=0;
    time_t currentTime;
    struct produit pV[100];
    printf("Donnez Le Code Produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
       if(strcmp(c,p[i].code) == 0){ // c == code return value 0
            printf("Donnez le nombre de ce produit qui a vendue: ");
            scanf("%d",&N);
                if(N <= p[i].quantite){
//                    Newprix = (p[i].prix * N) / (p[i].quantite);
//                    p[i].prix -= Newprix;
                    p[i].quantite -= N;


                    //time Acheter
                    time(&currentTime);
                    strcpy(p[i].time , ctime(&currentTime));

                    //Afichage Acheter
                    printf("\n\t\tPorduit\t\tCode\tQuantitie\t\tDate Acheter\n");
                    printf("\t\t-------------------------------------------------------------------\n");
                    printf("\t\t%d\t\t%s\t%d\t\t%s\n",i+1,p[i].code,p[i].quantite,p[i].time);

                }else{
                    printf("La Quantite n'est pas suffisante\n");
                }
       }else{
            printf("Le code N'existe pas dans la liste des produit\n");
       }
    }

}

//Recherche les Produits
void OperationRechercheProduits(){
    int op;
    do{
    printf("1 - Recherche Par Code:\n");
    printf("2 - Recherche Par Quantite:\n");
    printf("3 - Etat du Stock:\n");
    printf("4 - Back! Menu\n");
    scanf("%d",&op);

        switch(op){
        case 1:
            system("cls");
            codeP();
            break;
        case 2:
            system("cls");
            quantiteP();
            break;
        case 3:
            system("cls");
            etatStock();
            break;
        case 4:
            system("cls");
            OperationProduits();
            break;
        default:
            printf("Choise Correcte Operation!!!");
        }
    }while(op != 3);

}

//Function codeP
void codeP(){
    int i;
    char c[14];
    printf("Entrez la Code Produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
        if(strcmp(c , p[i].code) == 0){
            printf("Code: %s\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
            break;
        }
        else{
            printf("Le code N'existe pas dans la liste des produit!");
        }
    }

}
//Function quantiteP
void quantiteP(){
    int i,q;
    printf("Entrez la Quantite Produit: ");
    scanf("%d",&q);
    for(i=0; i<numTotalP; i++){
        if(q == p[i].quantite){
            printf("Code: %s\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
        }
    }
}
//Etat du stock
void etatStock(){
    for(int i=0; i<numTotalP; i++){
        if(p[i].quantite < 3){
            printf("Code: %s\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
        }
    }
}


int main()
{

    OperationProduits();
    return 0;
}
