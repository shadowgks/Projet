#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int numTotalP = 0;
//Structures Section
struct produit{
    //Members
    char code[14];
    char nom[30];
    int quantite;
    float prix;
    time_t time;
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
        printf("6 - Acheter le Produit\n");
        printf("7 - Quitter De Programme\n");
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
                acheterProduit(p);
                break;
            case 7:
                printf("By by\n");
                break;
        }

    }while(OP != 7);

}
//ajouterProduits
void ajouterProduits(struct produit p[100],int N){
    //ajouter
    for(int i=numTotalP; i<numTotalP+N; i++){
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
void afficherProduit(struct produit p[100]){
    //afficher
    printf("\n\t\t\t\tPorduit\t\tCode\tNom\tQuantitie\tPrix\tDate Achate\n");
    printf("\t\t\t\t------------------------------------------------------------\n");
    for(int j=0; j<numTotalP; j++){
        printf("\t\t\t\t%d\t\t%s\t%s\t%d\t\t%.2fDH\t%s\n",j+1,p[j].code,p[j].nom,p[j].quantite,p[j].prix,p[j].time);
    }
}
//Function l’ordre alphabétique croissant du nom.
void orderAlpha(struct produit p[100]){
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
//l’ordre  décroissant du prix. //Triage par pivot
void orderPrix(struct produit p[100]){
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
void operationTrier(struct produit p[100]){
    int op;
    do{
    printf("1 - L’ordre Alphabetique Croissant Du Nom:\n");
    printf("2 - L’ordre Decroissant Du Prix:\n");
    printf("3 - Back! Menu\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            orderAlpha(p);
            afficherProduit(p);
            break;
        case 2:
            orderPrix(p);
            afficherProduit(p);
            break;
        case 3:
            system("cls");
            OperationProduits(p);
            break;
    }
    }while(op != 3);
}

//Function mettre à jour la quantité après avoir introduit le code produit
void acheterProduit(struct produit p[100]){
    int N,count;
    char c[14];
    float k=0;
    //Time Current
    time_t currentTime;
    printf("Donnez Le Code Produit: ");
    scanf("%s",c);
    for(int i=0; i<numTotalP; i++){
       if(strcmp(c,p[i].code) == 0){ // c == code return value 0
            printf("Donnez le nombre de ce produit qui a vendue: ");
            scanf("%d",&N);
                if(p[i].quantite >= N){
                    k = (p[i].prix * N) / (p[i].quantite);
                    p[i].prix -= k;
                    p[i].quantite -= N;

                    printf("\n\t\t\t\t\tCode\tNom\tQuantitie\tPrix\tDate Achate\n");
                    printf("\t\t\t\t------------------------------------------------------------\n");
                    printf("\t\t\t\t\t%s\t%s\t%d\t\t%.2fDH\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
                    //time Acheter
                    time(&currentTime);
                    p[i].time = ctime(&currentTime);
                    printf("\t\t\t\t\t%s\n",ctime(&currentTime));

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
////Recherche les Produits
//void rechercheProduits(struct produit p[100]){
//}

//Function codeP
void codeP(struct produit p[100], int numTotalP, char c){
    int i;
    printf("Donnez le code Produit: ");
    scanf("%s",&c);
    for(i=0; i<numTotalP; i++){
        if(c == p[i].code){
            printf("Code: %d\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
            break;
        }
    }
}
//Function quantiteP
void quantiteP(struct produit p[100], int numTotalP, double q){
    int i;
    printf("Donnez la Quantite Produit: ");
    scanf("%d",&q);
    for(i=0; i<numTotalP; i++){
        if(q == p[i].quantite){
            printf("Code: %d\nNom: %s\nQuantitie: %d\nPrix: %.2f\n",p[i].code,p[i].nom,p[i].quantite,p[i].prix);
            break;
        }
    }
}
//Etat du stock


int main()
{
    struct produit ps[100];
    OperationProduits(ps);
    return 0;
}
