### 解题思路
![QQ图片20200117102129.png](https://pic.leetcode-cn.com/a3bdaf5a0fc85d9d1eb329ecd83dccc72c7fbcd9e36ce828bc3a4782611e2c5b-QQ%E5%9B%BE%E7%89%8720200117102129.png)

+ 从右往左找到第一个不为九的数，将该位以后的数改为0。
### 代码

```cpp
class Solution {
public:
    void changeto0(vector<int>&nums,int pos)//将pos后数位变0
    {
        for(int i=pos;i<nums.size();i++)
            nums[i] = 0;
    }
    vector<int> plusOne(vector<int>& digits) {
        int dix = digits.size()-1;
        while(dix>=0&&digits[dix]==9)
            dix--;
        if(dix<0)//最高位进位
        {
            changeto0(digits,0);
            digits.insert(digits.begin(),1);
        }
        else
        {
            digits[dix] += 1;
            changeto0(digits,dix+1);
        }
        return digits;
    }
};
```