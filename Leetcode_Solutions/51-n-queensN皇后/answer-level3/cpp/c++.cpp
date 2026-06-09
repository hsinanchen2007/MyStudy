### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> x;
    int countn=0;
    int num=0;
    vector<vector<string>> mvec;
    string s;
    vector<vector<string>> solveNQueens(int n) {
        x = vector<int>(n,0);
        num = n;
        for(int i=0;i<n;++i)
        s+=".";

        Backtrack(0);
        cout<<countn<<endl;
        
        
        return mvec;
    }
    bool Place(int t)
    {
        bool ok = true;
        for(int j=0;j<t;++j)
        {
            if(x[t]==x[j]||t-j==fabs(x[t]-x[j]))
            {
                ok=false;
                break;
            }
        }
        return ok;
    }
    void Backtrack(int t)
    {
        
        if(t==num)
        {
            countn++;
            vector<string> temvec;
            for(int i=0;i<num;i++)
            {
                string s0 = s;
                s0[x[i]] = 'Q';
                temvec.push_back(s0); 
            }
            mvec.push_back(temvec);
        }else
        {
            for(int i =0;i<num;++i)
            {
                x[t] = i;
                if(Place(t))
                Backtrack(t+1);
            }
        }
    }
};
```