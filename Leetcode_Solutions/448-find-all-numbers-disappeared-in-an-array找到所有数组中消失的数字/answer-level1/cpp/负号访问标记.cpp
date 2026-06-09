### 解题思路
使用负号来作为访问标记

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> dis;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int a = abs(nums[i])-1;
            nums[a] = -abs(nums[a]);
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) dis.push_back(i+1);
        }
        return dis;
    }
};
```