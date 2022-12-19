```
class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int x_or = x ^ y;
        int cnt = 0;
        while(x_or)
        {
            x_or = x_or & (x_or - 1);
            ++cnt;
        }
        return cnt;
    }
};
```
