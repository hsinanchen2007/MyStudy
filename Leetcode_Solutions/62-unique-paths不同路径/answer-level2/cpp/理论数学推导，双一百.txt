### 解题思路
其实这道题从数学上去推导反而更简单，首先，我们一共要走m + n - 2步，这是确定的，
并且，其中m - 1步是往下走的，即是排列组合了嘛，m + n - 2中选m - 1
![image.png](https://pic.leetcode-cn.com/685f0cbea3fbe70096485d28ba8796e47b7316869706dd39fc0ec4d1e9084da4-image.png)


### 代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n)
            swap(m, n);
        // m >= n
        double res = 1;
        double down = 1;
        for (float i = 0; i < n - 1; ++i)
        {
            res *= (m + n - 2 - i);
            down *= (n - i - 1);
        }
        cout << res << endl << down << endl;
        return res / down;
    }
};
```