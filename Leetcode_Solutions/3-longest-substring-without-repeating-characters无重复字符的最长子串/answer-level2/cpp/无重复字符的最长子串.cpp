### 解题思路
此处撰写解题思路
我的思路超级简单，先定义三个变量：step为返回的字符串长度，min_Postion为要返回字符串的开始下标，max_Postion为结束下标。当数组扫到i位置时，就检测1~i-1是否有和i相同的字符，如果有，假如下标为j，则min_POstionmin_Poostion变量就重新定义为j+1.max_Postion一直与i的值保持一致。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,min_Postion=0,max_POstion=0,step=0;
        while(s[i])
        {
            for( j=min_Postion;j<max_POstion;j++)
            {
                if(s[i]==s[j])
                {
                    min_Postion=j+1;
                    if(i-j>step)step=i-j;
                    break;
                }  
            }
            if(j==max_POstion&&max_POstion-min_Postion+1>step)
                step=max_POstion-min_Postion+1;
            i++;
            max_POstion=i;
        }
    return step;
    }
};

![20200317141739.png](https://pic.leetcode-cn.com/e230716622f2b9433527760c6bf98b36b6af7d9f50b3cf2e56786919521adea0-20200317141739.png)

