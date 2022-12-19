### 解题思路
[递归] C++ 击败100%用户，第一名
![image.png](https://pic.leetcode-cn.com/bea3257cf7436243ac80d1deb47a8a40ad2fc3973a47f6c26b69b3581b775628-image.png)

思路很简单：采用递归方法剥洋葱，一层一层剥掉输出，直到最后剥没有了。
verse是递归函数，输入每层剥离的开始坐标[starti,startj], lieLen和hangLen表示本次剥离矩阵的厚度。
注意：每次迭代，lieLen和hangLen要减少2.
迭代出口条件：lieLen和hangLen有一个为0即可，表示没有需要剥的了，退出。
每层剥离的方法：
按照旋转方向，每步走到顶点即可：向左->向下->向右->向上，遍历同时输出到返回数组即可。
复杂度O(N).
详见代码：

### 代码

```cpp
class Solution {
public:
int verse(vector<vector<int>> &matrix, int starti, int startj, vector<int> &returnVec, int lieLen, int hangLen)
{
    if (hangLen <= 0 || lieLen <= 0) {
        return 0;
    }

    // 1 向左横行
    int i = startj;
    for (; i < startj + lieLen; i++) {
        returnVec.push_back(matrix[starti][i]);
    }
    int lieindex = i - 1;
    // 2 向下竖列
    for (int i = starti + 1; i < starti + hangLen; i++) {
        returnVec.push_back(matrix[i][lieindex]);
    }

    // 3 向右横行
    for (int lieindex = startj + lieLen - 2; lieindex >= startj && hangLen - 1 > 0; lieindex--) {
        returnVec.push_back(matrix[starti + hangLen - 1][lieindex]);
    }
    // 4向上竖列
    for (int hangindex = starti + hangLen - 2; hangindex > starti && lieLen -1> 0; hangindex--) {
        returnVec.push_back(matrix[hangindex][startj]);
    }

    verse(matrix, starti + 1, startj + 1, returnVec, lieLen - 2, hangLen - 2);

    return 1;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> returnVec;
    if (matrix.size() == 0) {
        return returnVec;
    }
    // 递归逐层剥离输出
    verse(matrix, 0, 0, returnVec, matrix[0].size(), matrix.size());
    return returnVec;
}
};
```