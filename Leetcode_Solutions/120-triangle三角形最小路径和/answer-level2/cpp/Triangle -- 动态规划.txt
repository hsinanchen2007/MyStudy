### 解题思路
坐标系的动态规划：
1.state 
    1）找最大最小:f(n) = max(min) (f(n-1),f(n-2));
    2）找是不是，能不能 f(n) = f(n-1) && f(n-2);
    3）找和，f(n) = f(n-1) + f(n-2);

2.总结（！上一步）的结果怎么得出这一步的结果；

3.初始化，把确定的结果初始化了；

4.多重循环，把结果补上；

5.输出最终结果；

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        // 初始化
        for(int i = 1; i < triangle.size(); i++) {
            triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
            triangle[i][i] = triangle[i][i] + triangle[i - 1][i- 1];
        }
        // f(x, y) = f(x - 1, y) + f(x - 1, y - 1)
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 1; j < i; j++) {
                triangle[i][j] = min(triangle[i-1][j-1], triangle[i-1][j]) + triangle[i][j];
            }
        }
        int sum = INT_MAX;
        int index = triangle.size() - 1;
        for (int i = 0; i < triangle[index].size(); i++) {
            cout<<triangle[index][i]<<endl;
            sum = min(triangle[index][i], sum);
        } 
        return sum;
    }
};
```