### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // 原地修改，自底向上，额外空间O(0);
    // 从倒数第二层起，每一个元素都加上下一行中相邻的较小节点，得到路径和，最终第一行的唯一值就是三角形最小路径和。
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     for (int i = triangle.size() - 2; i >= 0; i--) {
    //         for (int j = 0; j < triangle[i].size(); j++) {
    //             triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    //         }
    //     }
    //     return triangle[0][0];
    // }
    
    // O(n)解法
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        // dp数组获取到三角形最下边一行的数组元素
        vector<int> dp = triangle.back();
        // 从倒数第二行起，每一个元素都加上下一行中相邻的较小节点，得到路径和，保存在dp数组的对应位置。所以dp数组只保留当前行下一行到底部的最小值。
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j < triangle[i].size(); j++)
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
        return dp[0];
    }
};



#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    vector<int> dp = triangle.back();
    for (int i = triangle.size() - 2; i >= 0; i--)
        for (int j = 0; j < triangle[i].size(); j++)
            dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
    return dp[0];
}

int main() {
    vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout << minimumTotal(triangle) << endl;
}



```