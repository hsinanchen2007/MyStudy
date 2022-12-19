![image.png](https://pic.leetcode-cn.com/7400bb12ae158cd7bb1ac01bd2e2cba9c0ea4f932fd87efb4a2c74cb142f30a0-image.png)
```cpp
class Solution {
public:
// 两步：
// 1、先给所有值初始化为1
// 2、再利用动态方程dp[i][j] = dp[i-1][j-1]+dp[i-1][j] 赋值给中间值
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vTemp(numRows); //定义二维数组
        //遍历每一行，构造边界值
        for(int i = 0; i < numRows; i++) {
            vTemp[i] = vector<int>(i+1,1); //初始化每一行，每一行数组长度为i+1，初始化为1
            //在每一行中
            for (int j = 1; j < vTemp[i].size() - 1; j++) {
                vTemp[i][j] = vTemp[i-1][j-1] + vTemp[i-1][j];
            }
        }
        return vTemp;
    }
};
```
