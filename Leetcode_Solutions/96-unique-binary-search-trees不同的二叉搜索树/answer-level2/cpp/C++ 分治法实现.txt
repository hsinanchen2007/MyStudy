```
class Solution {
public:
    int numTrees(int n) {
        int* memo = new int[n];
        memset(memo, 0, sizeof(int) * n);
        return numTrees(1, n, memo);
    }

    int numTrees(int lptr, int rptr, int* memo)
    {
        if (memo[rptr - lptr] != 0)
            return memo[rptr - lptr];
        
        if (lptr == rptr)
            return memo[0] = 1;
        int pathNum = 0;
        for (int i = lptr; i <= rptr; i++)
        {
            if (i == lptr)
                pathNum += numTrees(i + 1, rptr, memo);
            else if (i == rptr)
                pathNum += numTrees(lptr, i - 1, memo);
            else
                pathNum += numTrees(i + 1, rptr, memo) * numTrees(lptr, i - 1, memo);
        }

        return memo[rptr - lptr] = pathNum;        
    }
};
```
