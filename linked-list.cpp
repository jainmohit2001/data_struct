#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct node{
	int x;
	int y;
	struct node* ptr;
};

void AddFirst(struct node **start,int a,int b){
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL){
		return;
	}
	temp->x = a;
	temp->y = b;
	temp->ptr = *start;
	*start = temp;
}
int DelFirst(struct node **start){
 	if(*start == NULL){
 		return -1;
 	}
 	else{
 		struct node *temp = *start;
 		*start = (*start)->ptr;
 		free(temp);
 	}
 	return 0;
 }

int Del(struct node **start,int x1, int y1){
 	struct node *temp = *start;
 	struct node *prev = NULL;
 	while(temp != NULL){
 		if(temp->x == x1 && temp->y == y1){
 			if(temp == *start){
 				int x=DelFirst(start);
 				return x;
 			}
 			prev->ptr = temp->ptr;
 			free(temp);
 			return 0;
 		}
 		else{
 			prev = temp;
 			temp = temp->ptr;
 		}
 	}
 	return -1;
 }

int searchd(struct node *start, int d){
	int ctr=0;
	struct node* temp = start;
	while(temp != NULL){
		float dist = ((float)temp->x*(float)temp->x) + ((float)temp->y*(float)temp->y);
		if((float)d >= sqrt(dist)){
			ctr++;
		}
			temp = temp->ptr;
	}
	if(ctr==0){
		return -1;
	}
return ctr;
}
string Search(struct node* start,int x1,int y1){
	string s= "False";
	struct node *temp = start;
	while(temp != NULL){
		if(temp->x == x1 && temp->y == y1){
			s = "True";
			return s;
		}
		else{
			temp = temp->ptr;
		}
	}
	return s;
}

int Length(struct node*start){
 	int len=0;
 	struct node*temp = start;
 	while(temp != NULL){
 		len++;
 		temp = temp->ptr;
 	}
 	return len;
}
void print(struct node *start){
	struct node *temp = start;
	while(temp != NULL){
		cout<<"("<<temp->x<<","<<temp->y<<") ";
		temp = temp->ptr;
	}
	cout<<endl;
}


int main(){
	struct node *head = NULL;
	return 0;
}
