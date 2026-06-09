### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //或者贪心
        vector<int> va;
        vector<int> vb;
        int nSize=seq.size();
        vector<int> vresult;
        vresult.resize(nSize);
        for(int i=0;i<nSize;++i)
        {
            if(seq[i]=='(')
            {
                if(va.size()>vb.size())
                {
                    //fangdao b
                    vresult[i]=1;
                    vb.push_back('(');
                }
                else
                {
                    vresult[i]=0;
                    va.push_back('(');
                }
            }
            else
            {
                if(va.size()<=vb.size())
                {
                    vb.pop_back();
                    vresult[i]=1;
                }
                else
                {
                    va.pop_back();
                    vresult[i]=0;
                }
            }
        }
        return vresult;
    }
};
```
始终让当前a b 联合的深度最低