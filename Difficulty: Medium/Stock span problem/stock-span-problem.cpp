//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stock's price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> v;
       stack<pair<int,int>> s;
       
       for(int i=0; i<n; i++){
           if(s.empty()) {
               v.push_back(-1);
           }
           else if(!s.empty() && s.top().first > price[i]){
               v.push_back(s.top().second);
           }
           else if(!s.empty() && s.top().first <= price[i]){
               while(!s.empty() && s.top().first <= price[i]){
                   s.pop();
               }
               if(s.empty()){
                   v.push_back(-1);
               } else {
                   v.push_back(s.top().second);
               }
           }
           s.push({price[i], i});
       }
       
       vector<int> ans(n);
       for(int i = 0; i < n; i++){
           ans[i] = i - v[i];
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends