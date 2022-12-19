### 解题思路
题目好像没啥特殊要求，弄一个新数组再搞几个for循环就完事了。
先把题目的数组A复制到另外一个数组B去。
先看某个数字是否为0，如果是0的话，把B数组对应的那一行和那一列弄0就好。
最后再把B数组复制回A数组即可。

![image.png](https://pic.leetcode-cn.com/22eb78a942d331f439ee2295dff2af7f414b0611a925a3155bb310a847bada1f-image.png)


### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> newMatrix = matrix;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[i].size(); j++)
                if(matrix[i][j]==0){
                    for(int k = 0; k < matrix.size(); k++)
                        newMatrix[k][j] = 0;
                    for(int m = 0; m < matrix[i].size(); m++)
                        newMatrix[i][m] = 0;
                }
                
        matrix = newMatrix;
    }
};

```