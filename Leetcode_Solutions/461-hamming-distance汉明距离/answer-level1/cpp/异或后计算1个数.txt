```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        int dis = x ^ y;
        while(dis)
        {
            dis &= dis-1;
            ret++;
        }
        return ret;
    }
};
```
