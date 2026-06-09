### 1.计算最大的补偿值。
### 2.采用滑动窗口计算即可。
### 3.时间复杂度O(N),空间复杂度O(1).
```
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int max_save = 0;
        int curr_save = 0;
        int satisf = 0;
        
        for(int i = 0;i < n; ++i){
            satisf += (grumpy[i] == 0?customers[i]:0);
            curr_save += customers[i]*grumpy[i];
            if(i >= X-1){
                max_save = max(max_save,curr_save);
                curr_save -= customers[i-X+1]*grumpy[i-X+1];
            }
        }
        
        return satisf + max_save;
    }
};
```