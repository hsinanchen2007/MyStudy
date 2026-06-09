### 解题思路
直接暴力模拟题意即可。
### 代码
```
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ve;
        for(int i = 0;i < nums.size();i += 2)
        {
            int a = nums[i];
            int b = nums[i + 1];
            for(int j = 0;j < a;j ++)
            {
                ve.push_back(b);
            }
            
        }
        return ve;
        
    }
};
```

