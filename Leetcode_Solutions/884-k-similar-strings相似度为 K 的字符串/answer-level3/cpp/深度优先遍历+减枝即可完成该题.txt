### 解题思路
深搜+剪枝即可完成，
当前字符不同时两种方式：1、找A串中的A[k]==B[now]&&A[now]==B[k] （找到之后即可剪枝，直接return即可，贪心策略可知！！！）
                    2、情况1不成立时，只能寻找A[k]==B[now]的情况(此处需要回溯，因为不知道怎么交换是最优情况！！！)

### 代码

```cpp
class Solution {
public:
    int min1=INT_MAX;
    unordered_map<string,int> mp;
    void dfs(int tp,string now,string B,int k)
    {
        if(now==B)
        {
            if(tp<min1)
                min1=tp;
            return;
        }
        if(now[k]==B[k])
            dfs(tp,now,B,k+1);
        else
        {
            char temp=now[k];
            for(int i=k+1;i<=B.size();++i)
            {
                if(B[i]==temp&&now[i]==B[k])
                {
                    swap(now[i],now[k]);
                    dfs(tp+1,now,B,k+1);
                    return ;
                }
            }
            for(int i=k+1;i<=B.size();++i)
            {
                if(now[i]==B[k])
                {
                    swap(now[i],now[k]);
                    dfs(tp+1,now,B,k+1);
                    swap(now[i],now[k]);
                }
            }
        }
    }
    int kSimilarity(string A, string B) {
        dfs(0,A,B,0);
        return min1;
    }
};
```