### 解题思路

![2020-04-02 15-24-37 的屏幕截图.png](https://pic.leetcode-cn.com/a0294dad565909588f2aa598d446d142976ad23005faebfa50110c7316b0c553-2020-04-02%2015-24-37%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```cpp
class Solution {
public:
    struct Coordinate {
        int x;
        int y;
    };

    int maximalRectangle(vector<vector<char>>& matrix) {

        int ans = 0;
        int N = matrix.size();
        if (N < 1) return ans;
        int M = matrix[0].size();

        vector<Coordinate> v;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++)
            {
                if (matrix[y][x] == '1') v.push_back({x, y});
            }
        }

        for (auto coord : v) {

            int left = coord.x; int right = coord.x; int height = 1;

            for (int i = coord.x; i < M; i++) {
                if (matrix[coord.y][i] == '1') 
                    right = i;
                else
                    break;
            }

            bool stop = false;
            for (int j = coord.y + 1; j < N; j++) {
                for (int i = left; i <= right; i++) {
                    if (matrix[j][i] == '0') {
                        stop = true;
                        break;
                    }
                }
            
                if (stop) break;
                height++;
            }

            stop = false;
            for (int j = coord.y - 1; j >= 0; j--) {
                for (int i = left; i <= right; i++) {
                    if (matrix[j][i] == '0') {
                        stop = true;
                        break;
                    }
                }

                if (stop) break;
                height++;
            }
        
            ans = max(ans, (right - left + 1) * height);
        }

        return ans;
    }
};
```