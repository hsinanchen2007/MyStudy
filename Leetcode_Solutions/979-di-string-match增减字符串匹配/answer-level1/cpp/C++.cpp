### 解题思路
通过分析题干要求发现D所在的数字递减I数字递加

### 代码

```cpp
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len=S.length();
        int k=len;
        vector<int> sum(len+1,0);
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(S[i]=='D')
                sum[i]=k--;
            else 
                sum[i]=j++;
        }
        if(S[len-1]=='I')sum[len]=sum[len-1]+1;
        else sum[len]=sum[len-1]-1;
        return sum;
    }
};
```