### 解题思路
嗯，学习到一个新知识点  异或^

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int m=nums[0];
        for(int i=1;i<nums.size();i++){
            m^=nums[i];
        }
        return m;

    }
};
```