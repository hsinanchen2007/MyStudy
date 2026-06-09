### 解题思路
厉害

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n,n);
        int lastC = -n;
        for(int i=0;i<n;i++)
        {
            if(S[i]==C)
                lastC = i;
            res[i] = min(res[i],i-lastC);
        }

        for(int i=lastC-1;i>=0;i--)
        {
            if(S[i]==C)
                lastC = i;
            res[i] = min(res[i],lastC-i);
        }
        return res;
    }
};
```