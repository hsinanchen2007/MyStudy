### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/768a401bd0bcdf04a512b871ee9a53bedc87dd0bb0edbe588b7e142c98485ba0-image.png)
刚开始一直想如何一次旋转一个边，一直无法找到一种循环写法可以一个边一个边的转。
其实一开始这样的思想就是错误的
对于2维来说，总结经验就是循环是需要单一对称的。单一是一个元素。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        int n = matrix.size()-1;
        int layers = (n+1)/2;
        for (int i = 0; i < layers; i++) {
            for (int x = i; x < n-i; x++){
                int a = matrix[i][x];
                int b = matrix[x][n-i];
                int c = matrix[n-i][n-x];
                int d = matrix[n-x][i];
                matrix[i][x] = d;
                matrix[x][n-i] = a;
                matrix[n-i][n-x] = b;
                matrix[n-x][i] = c;
            }
        }
    }
};
```