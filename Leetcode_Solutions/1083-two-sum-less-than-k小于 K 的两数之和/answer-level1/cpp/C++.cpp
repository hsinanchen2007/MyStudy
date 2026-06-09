```
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int ans = -1;
        int n = A.size();
        
        for(int i = 0; i < n-1; ++i){
            int l = i;
            int r = n-1;
            
            while(r > l){
                if(A[l] + A[r] >= K){
                    --r;
                }else{
                    ans = max(ans,A[l]+A[r]);
                    break;
                }
            }
        }
        
        return ans;
    }
};
```