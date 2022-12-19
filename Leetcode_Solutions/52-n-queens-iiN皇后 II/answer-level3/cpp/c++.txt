### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> x;
    int countn=0;
    int num;
    int totalNQueens(int n) {
        num = n;
        x.resize(n);
        Backtrace(0);
        return countn;
    }
    bool place(int t)
    {
        for(int i=0;i<t;++i)
        {
            if(abs(x[i]-x[t])==abs(t-i)||x[t]==x[i])
            {
                return false;
            }
        }
        return true;
    }
    void Backtrace(int t)
    {
        if(t==num)
        {
            countn++;
        }else
        {
            for(int i=0;i<num;++i)
            {
                x[t] = i;
                if(place(t))
                {
                    Backtrace(t+1);
                }
            }
        }
    }
};
```