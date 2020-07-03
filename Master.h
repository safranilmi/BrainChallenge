
typedef int infotype;
typedef struct TElmtQueue *address;
typedef struct TElmtQueue{
	infotype Info;
	address Next;
}ElmtQueue;

typedef struct{
	address Head;
	address Tail;
}Queue;

#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail
#define InfoHead(Q) (Q).Head->Info
#define InfoTail(Q) (Q).Tail->Info

void Allocation(address *P, infotype X){

	*P = (address)malloc(sizeof(ElmtQueue));
	if(P != NULL){
		Info(*P) = X;
		Next(*P) = NULL;
	}else{
		(*P) = NULL;
	}
}

void Deallocation(address P){
	free(P);
}

bool IsEmpty(Queue Q){

	return ((Head(Q) == NULL) && (Tail(Q) == NULL));
}

void CreateEmpty(Queue *Q){

	Head(*Q) = NULL;
	Tail(*Q) = NULL;
}

void Add(Queue *Q, infotype X){
	address P;

	Allocation(&P, X);
	if(P != NULL){
		if(IsEmpty(*Q)){
			Head(*Q) = P;
		}else{
			Next(Tail(*Q)) = P;
		}
		Tail(*Q) = P;
	}
}

void Del(Queue *Q, infotype *X){
	address P;

	*X = InfoHead(*Q);
	P = Head(*Q);
	Head(*Q) = Next(Head(*Q));
	if(Head(*Q) == NULL){
		Tail(*Q) = NULL;
	}
	Deallocation(P);
}

