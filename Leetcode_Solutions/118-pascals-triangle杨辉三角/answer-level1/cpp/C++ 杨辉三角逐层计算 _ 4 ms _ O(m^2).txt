### 解题思路
按照杨辉三角题目的定义：元素等于左上方右上方元素的和；
逐层计算出各层的数组即可；

以行数i>=2为例：
默认首元素为1，随后各行从前半部分([1, i/2]的角标)迭代，此部分元素需要调用上一行左右上角累加；
后半部分([i/2+1, i])对称复制前半部分数组即可；

i=0,1时，该循环体同样支持；
下标容易写错，图示清楚一些：

![新文档 2020-02-19 22.55.12_1.jpg](https://pic.leetcode-cn.com/7df6e301cdeb3094a1ff5af58f8cf9567845ee1dfd1762a30d14869c40a5f4e2-%E6%96%B0%E6%96%87%E6%A1%A3%202020-02-19%2022.55.12_1.jpg)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i=0; i<numRows; ++i) {

            vector<int> row;
            row.push_back(1); // 首元素

            for (int j=1; j<=i/2; ++j) { //实际上到第三行才会运行此循环体
                //需要由上一行计算的元素
                row.push_back(result[i-1][j-1]+result[i-1][j]);
            }
            for (int j=i/2+1; j<=i; ++j) {
                //对称复制
                row.push_back(row[i-j]);
            }
            result.push_back(row);
        }
        return result;
    }
};
```