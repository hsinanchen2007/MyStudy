思路：因为需要原地旋转，所以要在矩阵内部交换元素，找规律发现，某点在顺时针旋转90°四次后会回到原点，于是可以从最外圈开始依次向内遍历，次数为n/2：
```
for(int layer = 0; layer < n/2; ++layer)
```
在圈数循环的内部，再嵌套一个循环，遍历当前圈的第一行（除开最后一个元素），判断条件为：
```
for(int j = layer; j < n-layer-1; ++j)
```
设A(i', j'), B(i'', j''), C(i''', j'''), D(i'''', j'''')四点为旋转后的点，满足以下关系：

```
i' + j'' = n - 1,  i'' = j'

i'' + j''' = n - 1,  i''' = j''

i''' + j'''' = n - 1,  i'''' = j'''

i'''' + j' = n - 1,  i' = j'''
```

代码就很清晰了，用一个长度为4的数组记录这几个点的值即可
完整解答如下：

```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> arr;
        for(int layer = 0; layer < n/2; ++layer){
            for(int j = layer; j < n-layer-1; ++j){
                arr.clear();
                arr.push_back(matrix[layer][j]);
                arr.push_back(matrix[j][n-1-layer]);
                arr.push_back(matrix[n-1-layer][n-1-j]);
                arr.push_back(matrix[n-1-j][layer]);
                matrix[j][n-1-layer] = arr[0];
                matrix[n-1-layer][n-1-j] = arr[1];
                matrix[n-1-j][layer] = arr[2];
                matrix[layer][j] = arr[3];
            }
        }
    }
};
```
