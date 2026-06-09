### 解题思路
return {}返回了一个空的vector
INT_MIN表示int类型的最小值
### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n*k == 0){
           return {}; 
        }
        vector<int> res;
        for(int i=0;i<n-k+1;i++){
             int max_num = INT_MIN;
             for(int j=i;j<i+k;j++){
                 max_num=max(nums[j],max_num);
             }
              res.push_back(max_num);
        }
        return res;
    }
};
```