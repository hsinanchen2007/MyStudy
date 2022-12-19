### 解题思路
c++双百解法shyshy

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
        {
            int c=max(nums[i]+a,b);
            a=b;
            b=c;
        }
        return b;
    }
};
```