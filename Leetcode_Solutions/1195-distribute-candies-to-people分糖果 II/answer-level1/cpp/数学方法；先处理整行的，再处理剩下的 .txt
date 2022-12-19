```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people, A = num_people*(num_people + 1)/2;
        int C = candies;
        int k = ((sqrt(1 + (long long)8*C) - 1)/(2*n));
        int left = C - (2*A + (k-1)*n*n)*k / 2;
        vector<int>ans(n, 0);
        int idx = 0;
        for(int i = k*n + 1; left; i++){
            if(left > i){
                ans[idx++] = i;
                left -= i;
            }else{
                ans[idx++] = left;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            ans[i] +=  k*(k-1)/2*n + k + i*k;
        }
        return ans;
    }
};
```