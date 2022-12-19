### 解题思路
状态转移矩阵变成了二维的了，需要保存两个串互相转换的关系；
具体思路见题解；
四月每日一题已经打不动卡了；
变成阅读理解+注释添加了。

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int D[n + 1][m + 1];//状态转移矩阵

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {//初始化矩阵的第一列，为另一个串为空时，需要多少步能变成空
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {//初始化矩阵的第一行，为另一个串为空时，需要多少步能变成空
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;//删除word1的一个字符
                int down = D[i][j - 1] + 1;//在word2里增加一个字符（等价于删除word2的一个字符）
                int left_down = D[i - 1][j - 1];//替换或者不替换
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};
```