#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Structures Section
struct produit{
    //Members
    char code[14], nom[30];
    int quantite;
    float prix;
};
struct produitVender{
    //Members
    char code[14], time[30];
    int quantite;
};

int numTotalP = 0;
int produitV = 0;
struct produit p[100];
struct produitVender pV[100];


//OperationProduits
void OperationProduits(){
    int N,OP;
    char c[14];
    do{
        printf("Choisir une operation:\n");
        printf("1 - Ajouter Un Nouveau Produit\n");
        printf("2 - Ajouter Un Produit\n");
        printf("3 - Rechercher Un Produit\n");
        printf("4 - Supprimer Un Produit\n");
        printf("5 - Afficher Les Produits\n");
        printf("6 - Trier Un Produit\n");
        printf("7 - Acheter le Produit\n");
        printf("8 - Afficher le Produits Vender\n");
        printf("9 - Quitter De Programme\n");
        scanf("%d",&OP);

        switch(OP){
            case 1:
                system("cls");
                ajouterOneProduits();
                break;
            case 2:
                system("cls");
                printf("Combien de produits souhaitez-vous saisir ?: ");
                scanf("%d",&N);
                ajouterProduits(N);
                break;
            case 3:
                system("cls");
                OperationRechercheProduits();
                break;
            case 4:
                supprimerP();
                break;
            case 5:
                system("cls");
                afficherProduit(N);
                break;
            case 6:
                system("cls");
                operationTrier();
                break;
            case 7:
                system("cls");
                acheterProduit();
                break;
            case 8:
                system("cls");
                afficherVender();
                break;
            case 9:
                system("cls");
                printf("Au Revoire :)\n");
                break;
            default:
            system("cls");
            printf("Choise Correcte Operation!!!\n");
        }
    }while(OP != 9);
}

//ajouter one produit
void ajouterOneProduits(){
    //ajouter
    printf("\nDonnez Le Code Produit: ");
    scanf("%s",p[numTotalP].code);
    //checkCode!
    int test = checkCode(p[numTotalP].code);
        if(test == 0){
            printf("Donnez Le Nom Produit: ");
            scanf("%s",p[numTotalP].nom); //Because Ineed Space
            printf("Donnez Le Quantitie Produit: ");
            scanf("%d",&p[numTotalP].quantite);
            printf("Donnez Le Prix Produit: ");
            scanf("%f",&p[numTotalP].prix);
            p[numTotalP].prix += 0.15 * p[numTotalP].prix; //TTC 15%
            numTotalP++;

        }else{
            printf("Cette code a deja ete annonces!!!");
        }
}

//ajouterProduits Plussier
void ajouterProduits(int N){
    //ajouter
    for(int i=0; i<N; i++){
        printf("\nDonnez Le Code Produit: ");
        scanf("%s",p[numTotalP].code);
        //checkCode!
        int test = checkCode(p[numTotalP].code);
        if(test == 0){
            printf("Donnez Le Nom Produit: ");
            scanf("%s",p[numTotalP].nom); //Because Ineed Space
            printf("Donnez Le Quantitie Produit: ");
            scanf("%d",&p[numTotalP].quantite);
            printf("Donnez Le Prix Produit: ");
            scanf("%f",&p[numTotalP].prix);
            p[numTotalP].prix += 0.15 * p[numTotalP].prix; //TTC 15%
            numTotalP++;
        }else{
            printf("Cette code a deja ete annonces!!!");
        }
    }
}

//Check code
int checkCode(char c[]){
    int i,test = 0;
    for(i=0; i<numTotalP; i++){
        if(strcmp(c , p[i].code) == 0){
            test++;
        }
    }
    return test;
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
        default:
            system("cls");
            printf("Choise Correcte Operation!!!\n");
    }
    }while(op != 3);
}

//Function mettre à jour la quantité après avoir introduit le code produit
void acheterProduit(){
    int N,count,i;
    char c[14];
//    float Newprix=0;
    time_t currentTime;
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

                    //Copy info vendu to structure Vendu
                    strcpy(pV[produitV].code, p[i].code);
                    pV[produitV].quantite = N;

                    //time Acheter
                    time(&currentTime);
                    strcpy(pV[produitV].time, ctime(&currentTime));
                    produitV++;
                    break;


                }else{
                    printf("La Quantite n'est pas suffisante\n");
                }
       }else{
            printf("Le code N'existe pas dans la liste des produit\n");
       }
    }

}

//Afficher Vender
void afficherVender(){
    printf("\n\t\tPorduit\t\tCode\tQuantitie\t\tDate Acheter\n");
    for(int i=0; i<produitV; i++){
        //Afichage Acheter Vender
        printf("\t\t-------------------------------------------------------------------\n");
        printf("\t\t%d\t\t%s\t%d\t\t%s\n",i+1,pV[i].code,pV[i].quantite,pV[i].time);
    }
}

//Recherche les Produits
void OperationRechercheProduits(){
    int op;
    do{
    printf("1 - Recherche Par Code:\n");
    printf("2 - Recherche Par Quantite:\n");
    printf("3 - Etat du Stock:\n");
    printf("4 - Alimenter le Stock\n");
    printf("5 - Back! Menu\n");
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
            alimenterStock();
            break;
        case 5:
            system("cls");
            OperationProduits();
            break;
        default:
            system("cls");
            printf("Choise Correcte Operation!!!\n");
        }
    }while(op != 5);

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

//Alimenter le stock
void alimenterStock(){
    int i,q=0;
    char c[14];
    printf("Entrez la Code Produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
        if(strcmp(c , p[i].code) == 0){
            printf("Donnez le Quantite: ");
            scanf("%d",&q);
            p[i].quantite = p[i].quantite + q;
            break;
        }
        else{
            printf("Le code N'existe pas dans la liste des produit!");
        }
    }
}

//Supprimer la produit
void supprimerP(){
    int pos=0;
    char c[14];
    printf("Entrez le code de l'element a Supprimer: ");
    scanf("%s",c);
        for(int i=0; i<numTotalP; i++){
            if(strcmp(c,p[i].code)==0){
                pos = i;
                break;
            }
        }
        for(int j=pos; j<numTotalP; j++){
            p[j] = p[j + 1];
        }
        numTotalP--;
}

//Statistique de vente
//total des prix des produits vendus


//Main
int main()
{
    OperationProduits();
    return 0;
}
