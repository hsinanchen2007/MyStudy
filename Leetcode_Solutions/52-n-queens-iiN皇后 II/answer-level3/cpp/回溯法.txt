### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/def82e791218f96a58f04a6821cf838104a14b4647f034aed2ff3ce9519d81ee-image.png)

### 代码

```cpp
class Solution {
public:
    int num = 0;
    int N = 0;

    void backStrack(int row, vector<int>& shu, vector<int>& pie, vector<int>& na) {

        if (row == N) {
            num++;
        }

        for (int col = 0; col < N; col++) {
            int p = col + row; int n = N - 1 + col - row;
            if (shu[col] || pie[p] || na[n]) continue;
            shu[col] = 1; pie[p] = 1; na[n] = 1;
            backStrack(row + 1, shu, pie, na);
            shu[col] = 0; pie[p] = 0; na[n] = 0;
        }
    }

    int totalNQueens(int n) {

        N = n;
        vector<int> shu(N, 0);
        vector<int> pie(2 * N - 1, 0);
        vector<int> na(2 * N - 1, 0);

        backStrack(0, shu, pie, na);

        return num;
    }
};
```