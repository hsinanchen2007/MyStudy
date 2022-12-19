计算前缀和后缀，以及滑动窗口即可
```
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int sum = 0;
        int ans = 0;
        vector<int> right(n,0);
        vector<int> left(n,0);
        vector<int> staisfy(n,0);
        sum = 0;/*left*/
        for(int i = 0;i < n; ++i){
            left[i] = sum;
            sum += (grumpy[i] == 0?customers[i] : 0);
        }
        sum = 0;/*right*/
        for(int i = n-1;i >= 0; --i){
            sum += (grumpy[i] == 0?customers[i] : 0);
            right[i] = sum;
        }
        sum = 0;/*no angry*/
        for(int i = 0; i < n; ++i){
            sum += customers[i];
            if(i >= X-1){
                staisfy[i-X+1] = sum;
                sum -= customers[i-X+1];
            }
        }
        for(int i = 0; i <= n - X; ++i){
            if(i != n-X){
                ans = max(ans,left[i] + staisfy[i] + right[i+X]);
            }else{
                ans = max(ans,left[i] + staisfy[i]);
            }
        }
        return ans;
    }
};
```