### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        int index[128]={0};
        int slength=s.length();
        for(int i=0;i<slength;i++)
        {
            int temp=int(s[i]);
            index[temp]++;
        }
        int re=0;
        bool flag=false;
        for(int i=0;i<128;i++)
        {
            if(index[i]>0)
            {
                re=re+index[i]/2;
            }
            if(index[i]%2==1)
            {
                flag=true;
            }
        }
        if(flag)
        {
            return re*2+1;
        }
        else
        {
            return re*2;
        }
    }
};
![image.png](https://pic.leetcode-cn.com/d2359be883c3b1993a49aae410a0ff3352adeba5e1e2f6e85b9ca79e4ed968de-image.png)


```