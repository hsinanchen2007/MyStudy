### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //最简单的异或操作  a^0=a;a^a=0;
        int ret=0;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            ret=nums[i]^ret;
        }
        return ret;
    }
};
```