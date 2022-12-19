# [最大子矩阵](https://leetcode-cn.com/problems/max-submatrix-lcci/)

## [二维前缀和](https://www.cnblogs.com/OIerShawnZhou/p/7348088.html)
![20200319144759.png](https://pic.leetcode-cn.com/4f591b6b11dc7f3cbc9ea40c217f142b3bd4237d817c3d67b4501997f100680a-file_1584625987037)
```
sum[i][j] = 
sum[i][j - 1] + sum[i - 1][j] + matrix[i - 1][j - 1] - sum[i - 1][j - 1];
```

### 二维前缀和+暴力$O(n^2m^2)$
```cpp
// O(n^2m^2)
if (n == 1 && m == 1)
    return ans;
int sum[205][205];
// init
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= m; j++)
    {
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + matrix[i - 1][j - 1] - sum[i - 1][j - 1];
    }
}
// brute force
int maxn = -(1 << 30);
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= m; j++)
    {
        for (int k = i; k <= n; k++)
        {
            for (int w = j; w <= m; w++)
            {
                int curSum = sum[k][w] + sum[i - 1][j - 1] - sum[k][j - 1] - sum[i - 1][w];
                if (curSum > maxn)
                {
                    maxn = curSum;
                    ans[0] = i - 1, ans[1] = j - 1, ans[2] = k - 1, ans[3] = w - 1;
                }
            }
        }
    }
}
```
## dp
### 一种错误的思路
事实证明，如果一开始思路是错的，怎么做都是错的

```
f[i][j]表示以(i,j)为右下角的最大矩阵和
f[i][j]=max{matrix[i][j],(i-1,j-1)转移,(i-1,j)转移,(i,j-1)转移}
g[i][j]表示以(i,j)为右下角的最大矩阵的左上角坐标
(i,j)从(i-1,j-1)或(i-1,j)或(i,j-1)转移过来：
```
![4566e6b10357bbe759524708d095a05.jpg](https://pic.leetcode-cn.com/810d047c90b7ba2b242b352e1a1eeec462061c4eaa1e94df3be03650e0ee9c81-file_1584625996019)
```cpp
x = g[i][j - 1].first, y = g[i][j - 1].second;
int left = sum[i][j] + sum[x][y] - sum[x][j] - sum[i][y];

x = g[i - 1][j].first, y = g[i - 1][j].second;
int top = sum[i][j] + sum[x][y] - sum[x][j] - sum[i][y];

x = g[i - 1][j - 1].first, y = g[i - 1][j - 1].second;
int diagonal = sum[i][j] + sum[x][y] - sum[x][j] - sum[i][y];
(看起来很有道理是吗?)
```
反例
```
-1  -2
8   -9
2    9

maxn=11!=10
2 9是转移不到的
```

__注意：最优子结构和无后效性__



### [正确的dp](https://leetcode-cn.com/problems/max-submatrix-lcci/solution/zhe-yao-cong-zui-da-zi-xu-he-shuo-qi-you-jian-dao-/)
把二维的最大矩阵和转化为一维的最大子段和

![20200319211407.png](https://pic.leetcode-cn.com/dcfef6b106f900f54cd39a58a8588594d1e6fe18a50046e05f1a9ec60e4ee82b-file_1584625989193)

枚举`i,j`,求数组`b`的最大字段和

```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
class Solution
{
public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans = {0, 0, 0, 0};
        int row[205];
        int maxn = -(1 << 30);
        for (int i = 0; i < n; i++)
        {
            memset(row, 0, sizeof(row));
            for (int j = i; j < n; j++)
            {
                int maxSum = 0;
                int left = 0;
                for (int k = 0; k < m; k++)
                {
                    row[k] += matrix[j][k];
                    maxSum += row[k];
                    if (maxSum > maxn)
                    {
                        maxn = maxSum;
                        ans[0] = i, ans[1] = left, ans[2] = j, ans[3] = k;
                    }
                    if (maxSum < 0)
                    {
                        maxSum = 0;
                        left = k + 1;
                    }
                }
            }
        }
        return ans;
    }
};
```
太难了，终于AC了

![20200319215201.png](https://pic.leetcode-cn.com/ad3ab694f720b41058d82ba5a89f150ee76dafc5a0466975610c150eee8fe3ad-file_1584625987434)