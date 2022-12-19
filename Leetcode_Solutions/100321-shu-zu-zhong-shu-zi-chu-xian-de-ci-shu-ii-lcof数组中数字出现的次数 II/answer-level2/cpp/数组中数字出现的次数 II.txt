### 解题思路
![image.png](https://pic.leetcode-cn.com/40c07b4c5376c8ea17e43eaf5ba403cbc2ec87a0bdc0b24a5d622f4785299d13-image.png)


### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitsum(32,0);
        for(int i=0;i<nums.size();i++)
        {
            long bit=1;
            for(int j=31;j>=0;j--)
            {
                if(bit&nums[i])
                    bitsum[j]+=1;
                bit<<=1;
            }
        }
        int res=0;
        for(int i=0;i<32;i++)
        {
            res<<=1;
            res+=bitsum[i]%3;
        }
        return res;
    }
};
```