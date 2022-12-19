### 解题思路
没有

### 代码

```cpp
class Solution {
public:
    int a[111111] = {0};
    
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++)a[nums[i]+50000]++;
        for (int i = 0; i < 111111; i++)while (a[i]--)ans.push_back(i-50000);
        
        return ans;
    }
};
```