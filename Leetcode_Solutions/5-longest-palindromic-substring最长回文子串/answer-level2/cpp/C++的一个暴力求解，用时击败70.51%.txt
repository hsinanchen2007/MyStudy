### 解题思路
先写一个算法复杂度O(n^2)的解法。
回文子串有两种情况：
1.第一种是子串长度为奇数，这种情况的特点是以某一个字母为中心，左右对称。此时我们可以通过判断每个字符的左右两边是否相等来更新我们的最大回文子串和其长度值。
2.第二中是子串长度为偶数，这种情况和奇数不同的一点就是其以两个字母为中心左右对称。在遍历的时候我们先判断当前的字母和下一个字母是相等的，然后触发此情况去计算偶数子串的长度。如果长度大于当前记录的子串长度，那么就更新记录子串为本子串，长度更新为本长度。

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int max = 0;  //记录当前已得到的全局最大回文子串的长度
        string max_sub_s;  //记录当前得到的最大回文子串
        for(int i =0;i<size;i++)
        {
            int i_max = 1;  //本循环不断更新的最大回文子串长度，单个字母就是，所以初始值设为1
            if(i_max>max)   //如果本循环的最大长度大于全局的回文子串长度，就更新。
            {
                max_sub_s=s[i];
                max=i_max;
            }
            int j = 1;
            while((i-j>=0)&&(i+j<size))  //进入循环，判断左右是否镜像对称
            {
                if(s[i-j]==s[i+j])    //左右值相同即增加i_max的计数
                {
                    i_max+=2;
                    if(i_max>max)
                    {
                        max_sub_s=s.substr(i-j,2*j+1);
                        max=i_max;
                    }
                }
                else break;   //一旦遇到不等的就停止本次for循环，开始下一个i的判断
                j++;
            }
        }
        //遍及偶数回文子串
        for(int i =0;i<size-1;i++)
        {
            int i_max = 0;
            int j = 1;
            if(s[i]==s[i+1])     //偶数回文子串的判定，一开始要判断当前字符是否与相邻的下一个字符是相等的，否则直接跳过
            {
                i_max+=2;
                if(i_max>max)
                {
                    max_sub_s=s.substr(i,2);
                    max=i_max;
                }
                while((i-j>=0)&&(i+j+1<size))
                {
                    if(s[i-j]==s[i+1+j]) 
                    {
                        i_max+=2;
                        if(i_max>max)
                        {
                            max_sub_s=s.substr(i-j,2*j+2);
                            max=i_max;
                        }
                    }
                    else break;
                    j++;
                }
            }
        }
        return max_sub_s;
    }
};
```