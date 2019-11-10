/*Find the frequency of each character in the given string*/
#include <bits/stdc++.h>
using namespace std;

int arr[240] = {0};
int hashfunction(char key){
	return(key-'!');
}

void Freq(string s){
	for(int i=0; i<s.length(); i++){
		int index= hashfunction(s[i]);
		arr[index]++;
	}

	for(int i=0; i<240; i++)
		if(arr[i]!=0){
            cout<<(char)(i+'!')<<" count: "<<arr[i]<<endl;
		}

}

int main(){
	string s;
	cin>>s;
	Freq(s);
}
