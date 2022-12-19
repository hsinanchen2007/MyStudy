### 解题思路

![image.png](https://pic.leetcode-cn.com/48a33b1efc9fe45fa7e1cb3b3bd3a3904d682219f8c03b3b2fede44981ef8a01-image.png)

从[0][0]位置开始访问，递归的访问每个位置的 上 下 左 右 位置；
当满足访问条件时，可访问个数加1；

### 代码

```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) { 
        int cnt = 0;
        std::vector< std::vector<int> > visited(m, std::vector<int>(n, 0));
        Travel(0, 0, k, m, n, visited, cnt);
        return cnt;
    }

    void Travel(int i, int j, int k, int m, int n, std::vector< std::vector<int> >& visited, int& cnt)
    {
        if (i >= m || j >= n || i < 0 || j < 0) return; 
        if (visited[i][j] == 0)
        {
            // 是否能访问[i][j]位置
            bool bCanArrived = false;
            int x = GetNumberBitSum(i);
            int y = GetNumberBitSum(j);
            if (x + y <= k)
            { 
                ++cnt;
                bCanArrived = true;
            } 
            visited[i][j] = 1; 

            // 能访问[i][j]位置，才能访问其上下左右的位置
            if (bCanArrived)
            {
                // 上
                Travel(i - 1, j, k, m, n, visited, cnt);        

                // 下
                Travel(i + 1, j, k, m, n, visited, cnt);

                // 左
                Travel(i, j - 1, k, m, n, visited, cnt);

                // 右
                Travel(i, j + 1, k, m, n, visited, cnt); 
            } 
        }
    }

    // 取某个整数的所有位数和
    int GetNumberBitSum(int value)
    {
        int sum = 0;
        while (value > 0)
        {
            int n = value / 10;
            sum += (value - n * 10);
            value = n;
        }
        return sum;
    }

};
```