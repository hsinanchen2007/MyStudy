### 解题思路
正反分别算一次最小距离即可,100%,97%...

### 代码

```cpp
class Solution {
public:
    vector<int> res;
    int pre;
    vector<int> shortestToChar(string S, char C) {

        bool init = true;
        for(int i = 0;i!=S.size();i++)
        {
            res.push_back(100000);
        }

        for(int i = 0;i!=S.size();i++)
        {
            if(S[i]==C)
            {
                if(init)
                {
                    init = false;
                }
                res[i] = 0;
                pre = 0;
            }
            else
            {
                if(!init)
                {
                    res[i] = pre+1;
                    pre++;
                }
            }
        }

        init = true;
        for(int i = S.size()-1;i>=0;i--)
        {
            if(S[i]==C)
            {
                if(init)
                {
                    init = false;
                }
                pre = 0;
            }
            else
            {
                if(!init)
                {
                    if(pre+1<res[i])
                    {
                        res[i] = pre+1;
                        pre++;
                    }
                }
            }
        }
        return res;
    }
};
```