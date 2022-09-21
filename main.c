#include <stdio.h>
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
    float prix;
};

int numTotalP = 0;
int numTotalproduitV = 0, produitVQ = 0;
struct produit p[100];
struct produitVender pV[100];



//OperationProduits
void OperationProduits(){
    int N,OP;
    char c[14];
    do{
        puts("\n____________Menu____________");
        printf("\nChoisir une operation:\n");
        printf("1 - Ajouter Un Nouveau Produit\n");
        printf("2 - Ajouter Un Produit\n");
        printf("3 - Rechercher Un Produit\n");
        printf("4 - Supprimer Un Produit\n");
        printf("5 - Afficher Les Produits\n");
        printf("6 - Trier Un Produit\n");
        printf("7 - Acheter le Produit\n");
        printf("8 - Afficher le Produits Vender\n");
        printf("9 - Total Prix Vendus\n");
        printf("10 - Moyenne Prix Vendus\n");
        printf("11 - Max Prix Vendus\n");
        printf("12 - Min Prix Vendus\n");
        printf("13 - Quitter De Programme\n");
        scanf("%d",&OP);

        switch(OP){
            case 1:
                system("cls");
                ajouterOneProduits();
                break;
            case 2:
                system("cls");
                ajouterProduits();
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
                prixTotalVendus();
                break;
            case 10:
                system("cls");
                prixMoyenneVendus();
                break;
            case 11:
                system("cls");
                prixMaxVendus();
                break;
            case 12:
                system("cls");
                prixMinVendus();
                break;
            case 13:
                system("cls");
                printf("Au Revoire :)\n");
                break;
            default:
            system("cls");
            printf("Choise Correcte Operation!!!\n");
        }
    }while(OP != 13);
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
void ajouterProduits(){
    int N;
    //ajouter
    printf("Combien de produits souhaitez-vous saisir ?: ");
    scanf("%d",&N);
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
            printf("Cette code a deja ete annonces!!!\n");
        }
    }
}

//Check code
int checkCode(char c[]){
    int i,test = 0;
    for(i=0; i<numTotalP; i++){
        if(strcmp(c , p[i].code) == 0){
            test++;
            break;
        }
    }
    return test;
}

//afficherProduit
void afficherProduit(){
    //afficher
    printf("\n\t\tPorduit\t\tCode\tNom\t\tQuantitie\tPrix\t\n");
    printf("\t\t--------------------------------------------------------------------------\n");
    for(int j=0; j<numTotalP; j++){
        printf("\t\t%d\t\t%s\t%s\t\t%d\t\t%.2fDH\n",j+1,p[j].code,p[j].nom,p[j].quantite,p[j].prix);
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
    printf("3 - Returne! Menu\n");
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
    int N,i;
    char c[14];
    int test = 0;
//    float Newprix=0;
    time_t currentTime;
    printf("Donnez Le Code Produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
       if(strcmp(c,p[i].code) == 0){ // c == code return value 0
            test = 1;
            printf("Donnez le nombre de ce produit qui a vendue: ");
            scanf("%d",&N);
                if(N <= p[i].quantite){
                    p[i].quantite -= N;

                    //Copy info produit to structure produitVendu
                    strcpy(pV[numTotalproduitV].code, p[i].code);
                    pV[numTotalproduitV].quantite = N;
                    produitVQ += N; //total quantitie produitVendus

                    pV[numTotalproduitV].prix = N * p[i].prix;

                    //time Acheter
                    time(&currentTime);
                    strcpy(pV[numTotalproduitV].time, ctime(&currentTime));
                    numTotalproduitV++;
                    break;

                }else{
                    printf("La Quantite n'est pas suffisante\n");
                }
       }
    }
    if(test == 0){
            printf("Le code N'existe pas dans la liste des produit\n");
    }

}

//Afficher Vender
void afficherVender(){
    printf("\n\t\tPorduit\t\tCode\tQuantitie\tPrix\t\tDate Acheter\n");
    for(int i=0; i<numTotalproduitV; i++){
        //Afichage Acheter Vender
        printf("\t\t---------------------------------------------------------------------------\n");
        printf("\t\t%d\t\t%s\t%d\t\t%.2f\t\t%s\n",i+1,pV[i].code,pV[i].quantite,pV[i].prix,pV[i].time);
    }
}

//Recherche les Produits
void OperationRechercheProduits(){
    int op;
    do{
    printf("1 - Recherche Par Code\n");
    printf("2 - Recherche Par Quantite\n");
    printf("3 - Etat du Stock\n");
    printf("4 - Alimenter le Stock\n");
    printf("5 - Returne! Menu\n");
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
    int i,test = 0;
    char c[14];
    printf("Entrez la Code Produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
        if(strcmp(c , p[i].code) == 0){
            test = 1;
            printf("Code: %s\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
            break;
        }
    }
    if(test == 0){
        printf("Le code N'existe pas dans la liste des produit!");
    }
}

//Function quantiteP
void quantiteP(){
    int i,q,test = 0;
    printf("Entrez la Quantite Produit: ");
    scanf("%d",&q);
    for(i=0; i<numTotalP; i++){
        if(q == p[i].quantite){
            test = 1;
            printf("Code: %s\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
            break;
        }
    }
    if(test == 0){
        printf("Le quantite N'existe pas dans la liste des produit!");
    }
}

//Etat du stock
void etatStock(){
    int test = 0;
    for(int i=0; i<numTotalP; i++){
        if(p[i].quantite < 3){
            test = 1;
            printf("Code: %s\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
            break;
        }
    }
    if(test == 0){
        printf("pas trouvé!!!\n");
    }
}

//Alimenter le stock
void alimenterStock(){
    int i,q,test=0;
    char c[14];
    printf("Entrez la Code Produit: ");
    scanf("%s",c);
    for(i=0; i<numTotalP; i++){
        if(strcmp(c , p[i].code) == 0){
            test = 1;
            printf("Donnez le Quantite: ");
            scanf("%d",&q);
            p[i].quantite += q;
            break;
        }
    }
    if(test == 0){
        printf("Le code N'existe pas dans la liste des produit!!!\n");
    }

}

//Supprimer la produit
void supprimerP(){
    int test = 0;
    char c[14];
    printf("Entrez le code de l'element a Supprimer: ");
    scanf("%s",c);
        for(int i=0; i<numTotalP; i++){
            if(strcmp(c,p[i].code)==0){
                test = 1;
                p[i] = p[i + 1];
                numTotalP--;
                break;
            }
        }

        if(test == 0){
            printf("Le code N'existe pas dans la liste des produit!!!\n");
        }
}

//Statistique de vente
//total des prix des produits vendus
void prixTotalVendus(){
    float prixTotal = 0;
    if(numTotalproduitV > 0){
        for(int i=0; i<numTotalproduitV; i++){
              prixTotal +=  pV[i].prix;
        }
        printf("Total Prix Vendus: %.2f\n",prixTotal);

    }else{
        printf("Prix Vendus Vide!!!\n");
    }
}

//Moyenne des prix des produits vendus
void prixMoyenneVendus(){
    float prixTotal = 0;
    float prixM = 0;
    if(numTotalproduitV > 0){
        for(int i=0; i<numTotalproduitV; i++){
              prixTotal +=  pV[i].prix;
              prixM = prixTotal / produitVQ;
        }
        printf("Moyenne Prix Vendus: %.2f\n",prixMT);

    }else{
        printf("Prix Vendus Vide!!!\n");
    }
}

//Max des prix des produits vendus
void prixMaxVendus(){
    int i,j;
    float prixMax;

    for(i=0; i<numTotalproduitV-1; i++){
        for(j=i+1; j<numTotalproduitV; j++){
            if(pV[i].prix < pV[j].prix){
                prixMax = pV[i].prix;
                pV[i].prix = pV[j].prix;
                pV[j].prix = prixMax;
            }
        }
    }
    printf("Prix Max est: %.2f\n",pV[0].prix);

}

//Min des prix des produits vendus
void prixMinVendus(){

    int i,j;
    float prixMin;

    for(i=0; i<numTotalproduitV-1; i++){
        for(j=i+1; j<numTotalproduitV; j++){
            if(pV[i].prix > pV[j].prix){
                prixMin = pV[i].prix;
                pV[i].prix = pV[j].prix;
                pV[j].prix = prixMin;
            }
        }
    }
    printf("Prix Min est: %.2f\n",pV[0].prix);


}


//Main
int main()
{
    OperationProduits();
    return 0;
}
