#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures Section
struct produit{
    //Members
    double code;
    char nom[30];
    int quantite;
    float prix;
};

//OperationProduits
void OperationProduits(struct produit p[100]){
    int N,OP;
    do{
        printf("Choisir une operation:\n");
        printf("1 - Ajouter Un Produit\n");
        printf("2 - Modifier Un Produit\n");
        printf("3 - Supprimer Un Produit\n");
        printf("4 - Afficher Les Produits\n");
        printf("5 - Trier Un Produit\n");
        printf("6 - Quitter De Programme\n");
        scanf("%d",&OP);


        switch(OP){
            case 1:
                printf("Combien de produits souhaitez-vous saisir ?: ");
                scanf("%d",&N);
                ajouterProduits(p,N);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                afficherProduit(p,N);
                break;
            case 5:
                operationTrier(p);
                break;
            case 6:
                printf("By by\n");
                break;
        }

    }while(OP != 6);

}
//Function ajouter
void ajouterProduits(struct produit p[100],int N){
    //ajouter
    for(int i=0; i<N; i++){
        printf("\nDonnez Le Code Produit: ");
        scanf("%d",&p[i].code);
        printf("Donnez Le Nom Produit: ");
        scanf("%s",p[i].nom); //Because Ineed Space
        printf("Donnez Le Quantitie Produit: ");
        scanf("%d",&p[i].quantite);
        printf("Donnez Le Prix Produit: ");
        scanf("%f",&p[i].prix);
        p[i].prix += 0.15 * p[i].prix;
    }
}
//afficherPreduit
void afficherProduit(struct produit p[100],int N){
    //afficher
    for(int j=0; j<N; j++){
        printf("Produit %d:\nCode: %d\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",j+1,p[j].code,p[j].nom,p[j].quantite,p[j].prix);
    }
}
//Function l’ordre alphabétique croissant du nom.
void orderAlpha(struct produit p[100],int count){
    int i,j;
    struct produit X;
    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            if(strcmp(p[i].nom,p[j].nom) > 0){ //if p[i].nom > p[j].nom So strcmp return value positive
                X = p[i];
                p[i] = p[j];
                p[j]= X;
            }
        }
    }
}
//Function l’ordre  décroissant du prix.
void orderPrix(struct produit p[100],int count){
    int i,j;
    struct produit X;
    for(i=0; i<count-1; i++){
        for(j=i+1; j<count; j++){
            if(p[i].prix < p[j].prix){
                X = p[i];
                p[i] = p[j];
                p[j]= X;
            }
        }
    }
}

void operationTrier(struct produit p[100]){
    int op;
    int count = 2;
    do{
    printf("1 - L’ordre Alphabetique Croissant Du Nom:\n");
    printf("2 - L’ordre Decroissant Du Prix:\n");
    printf("3 - Back! Menu\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            orderAlpha(p,count);
            afficherProduit(p,count);
            break;
        case 2:
            orderPrix(p,count);
            afficherProduit(p,count);
            break;
        case 3:
            OperationProduits(p);
            break;
    }
    }while(op != 3);
}

//Function mettre à jour la quantité après avoir introduit le code produit
void acheterProduit(struct produit p[100], int numTotal){
    int c;
    int N;
    printf("Donnez Le Code Produit: ");
    scanf("%d",&c);
    //Function Recherch
    printf("Donnez le nombre de ce produit qui a vendue: ");
    scanf("%d",&N);
    for(int i=0; i<numTotal; i++){
       if((c==p[i].code) && (p[i].quantite >= N))
            p[i].quantite-=N;
       else
            printf("Le code N'existe pas dans la liste des produit ou La Quantite n'est pas suffisante");
    }


}
int main()
{
    struct produit ps[100];
    OperationProduits(ps);
//    orderAlpha(ps,2);
//    afficherProduit(ps,2);
//    orderPrix(ps,2);
//    afficherProduit(ps,2);
    return 0;
}
