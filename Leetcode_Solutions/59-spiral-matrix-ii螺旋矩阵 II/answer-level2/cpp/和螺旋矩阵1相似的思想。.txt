![image.png](https://pic.leetcode-cn.com/a54ed899daee10041c0a5f41124b03ecd74d42816f42c01d7965a746abb1a181-image.png)

```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int dx = 0, dy = 1, x = 0, y = 0;

        int i = 1;
        while(i <= n * n) {
            res[x][y] = i;
            if(res[(x + dx + n) % n][(y + dy + n) % n]) {
                int d = dx;
                dx = dy; dy = -d;
            }
            x += dx; y += dy;
            i++;
        }

        return res;
    }
};
```
