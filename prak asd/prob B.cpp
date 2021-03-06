#include <iostream>
#include <stdlib.h>
using namespace std;

#define Nil -1         /* Nil adalah queue dengan elemen kosong */
#define MaxEl 20       /* MaxEl adalah ukuran maksimum table penampung */

typedef char infotype;
typedef struct {
	infotype T[MaxEl]; /* tabel penyimpan elemen */
	                   /* Indeks yang digunakan: 0..MaxEl-1 */
	int HEAD;          /* HEAD: alamat penghapusan */
	int TAIL;          /* TAIL: alamat penambahan */
} Queue;

/*** Konstruktor/Kreator  ***/
void CreateEmpty (Queue *Q){
    (*Q).HEAD = Nil;
    (*Q).TAIL = Nil;
}

/* Tes Kosong atau Penuh */
bool IsEmpty (Queue Q){
    return ( ((Q).HEAD == Nil) && ((Q).TAIL == Nil ));
}

/* Banyaknya elemen Queue */
int NbElmt(Queue Q){
    if(!IsEmpty(Q)){
        return 0;
    } else {
        if ((Q).HEAD <= (Q).TAIL){
            return ((Q).TAIL-(Q).HEAD + 1);
        } else {
            return (MaxEl-(Q).HEAD+(Q).TAIL+1);
        }
    }
}

bool IsFull(Queue Q){
    return ( NbElmt(Q) == MaxEl );
}


/*** Primitif Add/Delete ***/
void Add (Queue *Q, infotype X){
    	if (!IsFull(*Q)) {
		if(IsEmpty(*Q)) {
			(*Q).HEAD = 0;
			(*Q).TAIL = 0;
		} else {
			if ((*Q).TAIL==MaxEl) (*Q).TAIL=1;
			else (*Q).TAIL++;
		}
		(*Q).T[(*Q).TAIL] = X;
	} else {
		cout<<"\nQueue Penuh\n";
	}
}


void Del(Queue *Q, infotype * X){
    *X = (*Q).T[(*Q).HEAD];
    if ((*Q).HEAD == (*Q).TAIL){
        (*Q).HEAD = Nil;
        (*Q).TAIL = Nil;
    } else {
        if ((*Q).HEAD==MaxEl) (*Q).HEAD = 0;
        else (*Q).HEAD++;
    }
}

void OutQueue(Queue Q){
    char C;
    while(!IsEmpty(Q)){
        Del(&Q, &C);
        cout<<C<<" ";
    }
    cout<<endl;
}

int main(){
    Queue Q;
    string a;
    char x;
    int n;

    cin>>n;

    for (int i = 0; i<n; i++){
        CreateEmpty(&Q);
        cin>>a;
        for(int j = 0; j < a.length(); j++){
            if(a[j]=='1'||a[j]=='2'||a[j]=='3'||a[j]=='4'||a[j]=='5'||a[j]=='6'||a[j]=='7'||a[j]=='8'||a[j]=='9'||a[j]=='0'){
                Add(&Q, a[j]);
            } else if (a[j]=='_'){
                Del(&Q,&x);
            }
        }
        OutQueue(Q);
    }
}
