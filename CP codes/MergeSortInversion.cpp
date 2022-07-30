#include <bits/stdc++.h>
using namespace std;

long long int merge(int arr[], int l, int mid, int r){
	int n1= mid-l+1;
	int n2 = r-mid;
	int a[n1], b[n2];
	for(int i=0;i<n1;i++){
		a[i]=arr[l+i];
	}
	for(int i=0;i<n2;i++){
		b[i]=arr[mid+1+i];
	}
	int i=0,j=0;
	int k=l;
    long long inv=0;
	while(i<n1&&j<n2){
		if(a[i]<b[j]){
			arr[k]=a[i];
			k++,i++;
		}
		else{
			arr[k]=b[j];
			k++,j++;
            inv+= n-i;//also counts equal numbers as inversions because its in the else statement and the if statement has strict inequality
		}
	}
	while(i<n1){
		arr[k]=a[i];
			k++,i++;
	}
	while(j<n2){
		arr[k]=b[j];
			k++,j++;
	}
    return inv;

}
long long mergeSort(int arr[], int l,int r){
    long long inv=0;
	if(l<r){
		int mid = l+ (r-l)/2;
		inv+=mergeSort(arr, l, mid);
		inv+=mergeSort(arr, mid+1,r);
		inv+=merge(arr, l, mid, r);
	}
    return inv;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	//cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
		vector<int>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		int arr[n];
		for(int i=0;i<n;i++){
			arr[i]=v[i];
		}
		cout<<mergeSort(arr,0,n-1)<<"\n";
		//cout<<min(dp[n][0],dp[n][1])<<"\n";
	
	}
	return 0;
}