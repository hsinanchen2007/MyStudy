根据题意，相邻的相同的元素之间的间隔，最多只能为1，所以直接检查与n-1、n-2是否相同即可
```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int nSize = A.size();
        if (nSize == 0)
            return 0;
        int nTag = A[0];
        int nLast = A[1];
        for (int i = 2; i < nSize; ++i){
            int nTmp = A[i];
            if (nTmp == nTag || nTmp == nLast)
                return nTmp;
            else{
                nTag = nLast;
                nLast = nTmp;
            }
        }
        return nLast;
    }
};
```