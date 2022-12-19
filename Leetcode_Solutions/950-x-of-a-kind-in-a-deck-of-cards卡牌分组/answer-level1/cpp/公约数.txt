### 解题思路
1. 记录deck中所有数出现次数
2. 求他们的公约数，大于1就是true
![image.png](https://pic.leetcode-cn.com/ded29550f74ec4c63f0883cb46f884d2eae42925cd8a4dce175356d41c7b1fb2-image.png)

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> nums(10000);
        if(deck.size()<2) return false;
        for(auto i:deck)
        {
            nums[i]++;
        }
        int g=-1;
        // for(auto i:nums)
        // {
        //     if(i==1) return false;
        //     if(i<imin&&i>0) imin=i;
        // }
        for(auto i:nums)
        {
            if(i!=0)
            {
                if(g==-1)
                {
                    g=i;
                }
                else g=gcd(g,i);
            }
            
        }
        if(g<2) return false;
        return true;
    }
};
```