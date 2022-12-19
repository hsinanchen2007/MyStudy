### 解题思路
![码农黑板报.png](https://pic.leetcode-cn.com/f2cba6960d5cc658cbc71d7a6900daa6f8213f28c9ffc1826bf238197006ec0f-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
![image.png](https://pic.leetcode-cn.com/0f3b6e20ce8c50c92db3b5efb171c034464474a64f06324702003fbb68148984-image.png)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 1;
        int left = 0, right = n-1;
        int top = 0, bottom = n-1;
        while (true) {
            while (left <= right) {
                for (int j = left; j <= right; j++) {
                    res[top][j] = num++;
                }
                top++;
                break;
            }
            if (top > bottom) {
                break;
            }
            while (top <= bottom) {
                for (int i = top; i<= bottom; i++) {
                    res[i][right] = num++;
                }
                right--;
                break;
            }
            if (right < left) {
                break;
            }
            while (right >= left) {
                for (int j = right; j >= left; j--) {
                    res[bottom][j] = num++;
                }
                bottom--;
                break;
            }
            if (bottom < top) {
                break;
            }
            while (bottom >= top) {
                for (int i = bottom; i >= top; i--) {
                    res[i][left] = num++;
                }
                left++;
                break;
            }
            if (left > right) {
                break;
            }
        }
        return res;
    }
};
```