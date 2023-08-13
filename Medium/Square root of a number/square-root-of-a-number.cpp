//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
#define ll long long 
class Solution {
public:
    int floorSqrt(ll x) {
        ll s = 0;
        ll e = x;
        ll mid = s + (e-s)/2;
        ll target = x;
        ll ans = -1;
            
        while(s<=e)
        {
            if(mid*mid == target){
                return mid;
            }
            else if(mid*mid > target){
                e = mid -1;
            }
            else{
                ans = mid;
                s = mid + 1;
            }
            mid = s + (e-s)/2;
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
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends