### 解题思路
可以用递归做，每次求n-1的字符串然后对n-1的字符串处理。也可以用动态规划，即递归可以换成用数组存，按顺序求出1到n的字符串放入数组中。由于每次只要用到n-1的字符串，所以为了节约空间，用一个临时变量tem存储n-1的字符串。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string tem="1";
        for(int time=1;time<n;time++)
        {
        string ans;
        int i=1;int cur=0;
        while(tem[i-1])
        {
            if(tem[i]==tem[i-1])
                i++;
            else
            {
            ans+='0'+i-cur;
            ans+=tem[i-1];
            cur=i;
            i++;
            }          
        }
        tem=ans;
        }
        
        return tem;
    }
};
```