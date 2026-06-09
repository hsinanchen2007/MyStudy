### 解题思路
给出范围，那就取巧了，求大佬告知怎么改进内存消耗

### 代码

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ret{0};
        for(auto& ele:nums)
        {
            if(isDouble(ele))
            {
                ++ret;
            }
        }
        return ret;
    }

    bool isDouble(int& x)
    {
        if((x>=10 && x<=99)||(x>=1000 && x<=9999) || (x==100000))
        {
            return true;
        }
        return false;
    }
};
```