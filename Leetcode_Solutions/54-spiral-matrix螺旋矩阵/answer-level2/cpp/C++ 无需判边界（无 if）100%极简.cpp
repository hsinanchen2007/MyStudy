### 解题思路
![Snipaste_2020-03-17_22-33-20.png](https://pic.leetcode-cn.com/eec71fcc21e4e9f395668064bcfac7551fae87aa1eca16de4a144ee8cf29c659-Snipaste_2020-03-17_22-33-20.png)
如图，找规律即可发现：
先往右走 `n` 步，往下走 `m - 1` 步，往左走 `n - 1` 步， 往右走 `m - 2` 步……
并且，总共走了 n * m 步。


(当然，也可以先往右走 `n - 1` 步，往下走 `m` 步……)

#### 行走
为方便，可以设出生点 (0, -1)，那么，往右走了 n 步后就到达 (0, n - 1)，刚好是右边界。
所以首先需要做的是交替的使用 `n` 和 `m` 这两个值。可以用一个 bool 变量作为 flag 判断。
```cpp
int m = matrix.size() - 1;
int n = matrix[0].size();
int sum = (m + 1) * n;
bool flag = true;
while(sum)
{
    if(flag)
    {
        sum -= n;
        走(n--)步;
    }
    else
    {
        sum -= m;
        走(m--)步;
    }
    flag = !flag;
}
```

#### 转向
```int d[4][2] = {0,1, 1,0, 0,-1, -1,0};```
对于转向，一种经典的办法是建一个4 * 2 的二维数组，并对第一维循环。
比如：
```cpp
int d[4][2] = {0,1, 1,0, 0,-1, -1,0}; // 分别对应 向右、向下、向左、向上

int current_direction = 0;
int x = 0, y = 0;
while(true)
{
    x += d[current_direction][0];
    y += d[current_direction][1];
    current_direction = (current_direction + 1) % 4;
}
```


对以上思路整理一下可得
### 代码

```cpp
int d[4][2] = {0,1, 1,0, 0,-1, -1,0};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size() - 1;
        int n = matrix.empty()? 0 :  matrix[0].size();
        int x = 0, y = -1, cd = 0, sum = (m + 1) * n;
        while(sum)
        {
            int &r = cd & 1 ? m : n;
            for(int i = r; i > 0; --i)
            {
                x += d[cd][0];
                y += d[cd][1];
                ans.push_back(matrix[x][y]);
            }
            sum -= r--;
            cd = (cd + 1) % 4;
        }
        return ans;
    }
};
```