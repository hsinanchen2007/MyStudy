### 解题思路
当不等时进行三种情况判断即可，简单易懂！！！

### 代码

```cpp
class Solution {
public:
    int count=0;
    void dfs(string first,int f,string second,int s,int ct)
    {
        if(f==first.size()&&second.size()==s)
        {
            count=1;
            return;
        }
        else
        {
            if(first[f]==second[s])
                dfs(first,f+1,second,s+1,ct);
            else
            {
                if(ct==0)
                {
                    dfs(first,f+1,second,s,1);
                    dfs(first,f,second,s+1,1);
                    dfs(first,f+1,second,s+1,1);
                }
                else
                    return;
            }
        }
    }
    bool oneEditAway(string first, string second) {
        int l1=first.size();int l2=second.size();
        if(abs(l1-l2)>1)
            return 0;
        else
            dfs(first,0,second,0,0);
        return count;
    }
};
```