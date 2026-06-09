### 解题思路
判断所有数的最大公约数是否为1

### 代码

```cpp
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            if(nums[0]==1)return true;
            else return false;
        }

        int gcd=__gcd(nums[0],nums[1]);
        if(gcd==1)return true;
        for(int i=2;i<n;++i)
        {
            gcd=__gcd(gcd,nums[i]);
            if(gcd==1)return true;
        }
        return false;
    }
};
```