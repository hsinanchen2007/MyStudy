### 解题思路
先构造累加和序列,第一个置0，后面累加
双指针滑动窗口[i,j]，dis_sum[j]-dis_sum[i]表示第i个到第j个元素变换的花费。
如果花费小于maxCost并且j-i大于maxlength，修改maxlength；
如果花费大于maxCost，则j向后花费会更大，所以i向后。


### 代码

```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlength=0;
        //构造累加和序列
        int* dis_sum=new int[s.length()+1];
        dis_sum[0]=0;
        for(int i=1;i<=s.length();i++)
            dis_sum[i]=abs(t[i-1]-s[i-1])+dis_sum[i-1];
        //双指针
        int i=0,j=0;
        while(j<=s.length())
        {
            if(dis_sum[j]-dis_sum[i] <= maxCost)
            {
                if(maxlength<j-i) maxlength=j-i;
                j++;
            }
            else i++;
        }
        return maxlength;
    }
};
```