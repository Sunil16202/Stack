//https://practice.geeksforgeeks.org/problems/overlapping-intervals/0
//https://practice.geeksforgeeks.org/problems/overlapping-intervals/0


#include <bits/stdc++.h>
using namespace std;

#define pll pair<int,int>

void overlap(pll arr[], int n){
    sort(arr,arr+n);
    stack<pll> s;
    s.push(arr[0]);
    
    for(int i=1; i<n; i++){
        pll top = s.top();
        
        //no overlapping found
        if(top.second < arr[i].first){
            s.push(arr[i]);
        }
        //overlapping found
        else if(top.second < arr[i].second){
            top.second = arr[i].second;
            s.pop();
            s.push(top);
        }
        
    }
    stack<pll> prints;
    while(!s.empty()){
        pll top = s.top();
        s.pop();
        prints.push(top);
    }
    while(!prints.empty()){
        pll top = prints.top();
        prints.pop();
        cout<<top.first<<" "<<top.second<<" ";
    }
    cout<<endl;
    
}


int main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    pll arr[n];
	    for(int i=0; i<n; i++){
	        int x,y;
	        cin >> x;
	        cin >> y;
	        
	        arr[i] = {x,y};
	    }
	    overlap(arr, n);
	    
	}
	return 0;
}