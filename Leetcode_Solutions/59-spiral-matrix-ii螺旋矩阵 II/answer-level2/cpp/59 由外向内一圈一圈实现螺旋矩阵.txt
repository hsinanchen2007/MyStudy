### 解题思路
将整个过程看成是一圈一圈的叠加，分为(n+1)/2个步骤，每一步实现一圈，由外向内实现螺旋矩阵。
![image.png](https://pic.leetcode-cn.com/3b9fd6a358cb760c4ae478180c263589828312b4de134b28c8daae0c32f27b8c-image.png)

### 代码

```cpp
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n, vector<int> (n, 0));
        int m = 1;
        for (int i=0; i<(n+1)/2; i++) {
            m = circle(res, i, m);
        }
        return res; 
    }

private:
    int circle (vector<vector<int>> &res, int k/*从res(k, k)开始*/, int m) {
    //赋值一圈
        int n = res.size();
        int row=k, col=k;
        //case1:实心圈
        if (k == n-k-1) {
            res[row][col] = m;
            return 0;
        }
        //case2:空心圈
        while (col < n-k-1) {
            res[row][col] = m;
            m++;
            col++;
        }
        while (row < n-k-1) {
            res[row][col] = m;
            m++;
            row++;
        }
        while (col > k) {
            res[row][col] = m;
            m++;
            col--;
        }
        while (row > k) {
            res[row][col] = m;
            m++;
            row--;
        }
        return m;
    }
};
```