```
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy) return false;
        if (tx == sx && ty == sy) return true;
        int nx, ny;
        if (tx > ty) {
            nx = (tx % ty) + (sx / ty) * ty;
            ny = ty;
        } else {
            nx = tx;
            ny = (ty % tx) + (sy / tx) * tx;
        }
        if (nx == tx && ny == ty) return false;
        return reachingPoints(sx, sy, nx, ny);
    }
};
```
![image.png](https://pic.leetcode-cn.com/36ea46c90dd3c45af6b6c97f33c00a89ede75d80f17d86015514ec316b7e0d56-image.png)
