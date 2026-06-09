### 解题思路

首先我花了好长时间，才知道参数中 trangleSize 是 行数， 而 triangleColSize 则是存放每行列树的一维数组。

这道题目可能解法如下

- 暴力法，无非就是 `2 * 2 * 2 * 2 * ... * n`，也就是 2^n 种可能性， 全部罗列出来，算算结果就行了。
- 贪心法，每次选择当前最小的。不过主要是当前给的例子刚好能用而已，如果把5下面的1和8改成100，200，基本上也不是全局最优解
- 动态规划(DP). 分为不同的阶段，每个阶段保证最优。回溯的方法是从上往下，不断递归，而动态规划是从下往上不断的递推。

这里以听的覃超老师讲解的动态规划，加上自己的理解来介绍DP的做法。 后面的第一层表示三角形的底层。

第一层（初始状态）4，1，8，3.

第一层到第二层

- 6: 4, 1 , 选择1 -> 7
- 5: 1, 8 , 选择1 -> 6 
- 7: 8, 3 , 选择3 -> 10

状态更新为, 7, 6, 10

从第二层到第三层

- 3: 7, 6  , 选择6 -> 9
- 4: 6, 10 , 选择6 -> 10

状态更新为 9,10

第三层到第四层

- 2: 9,10  , 选择9 -> 11

因此最终是11.

### 代码

用C语言实现的唯一问题，脑中得时时刻刻想着内存分配和指针。

比如说，对于Python而言，想要获取数组的最后一个，那就是`res = triagnle[-1]`, 而C语言，就得写2个长代码

- 为数组分配内存：` int *res = (int*)malloc(sizeof(int) * triangleColSize[triangleSize-1]);` 
- 为数组初始化值: `    memcpy(res, triangle[triangleSize - 1],  sizeof(int) * triangleColSize[triangleSize-1]);`

同时C还没有最小值的函数，你还得手动实现。。

```c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){


    //由于不需要保存所有的状态，而且当前状态只和上一状态有关
    //因此只需要一个一维数组
    int *res = (int*)malloc(sizeof(int) * triangleColSize[triangleSize-1]);
    //结果最后一行就是原来的最后一行
    memcpy(res, triangle[triangleSize - 1], 
                sizeof(int) * triangleColSize[triangleSize-1]);
    //从最后第2行开始递推
    for (int i = triangleSize - 2; i >= 0 ; i-- ){
        //为新的行分配内存
        for ( int j = 0 ; j < triangleColSize[i]; j++){
            //第(i,j)元素的值为(i+1,j), (i+1,j+1)中的最小值
            int min =  res[j] < res[j+1] ?res[j] : res[j+1];
            res[j] = triangle[i][j] + min;

        }
    }
    return res[0];

}
```

我最开始的时候是保存的整体的数组，因此是个二维数组, 内存分配更加的麻烦。

```c
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    //新建二维表用于存放数据
    int **res = (int**)malloc(sizeof(int *) * triangleSize);
    //结果最后一行就是原来的最后一行
    res[triangleSize - 1] = triangle[triangleSize - 1];
    //从最后第2行开始递推
    for (int i = triangleSize - 2; i >= 0 ; i-- ){
        //为新的行分配内存
        res[i] = (int *)malloc(sizeof(int) * triangleColSize[i]);
        for ( int j = 0 ; j < triangleColSize[i]; j++){
            //第(i,j)元素的值为(i+1,j), (i+1,j+1)中的最小值
            int min =  res[i+1][j] < res[i+1][j+1] ?res[i+1][j] : res[i+1][j+1];
            res[i][j] = triangle[i][j] + min;

        }
    }
    return res[0][0];

}
```


最后用Python又实现了一遍，感觉写代码真轻松

```python
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        res = triangle[-1]
        for i in range(len(triangle) -2 , -1, -1):
            for j in range(len(triangle[i])):
                res[j] = min(res[j], res[j+1]) + triangle[i][j]

        return res[0]
```

转眼间，一个月过去了, 我学习了`C++`。下面是同样的逻辑，用`C++`进行实现。

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size(); //高度 

        vector<int> res(triangle[h-1].begin(), triangle[h-1].end());

        for( int i = h - 2 ; i >= 0; i--){
            for (int j = 0; j < triangle[i].size(); j++){
                res[j] = min(res[j], res[j+1]) + triangle[i][j];
            }
        }
        return res[0];

    }
};
```

这次状态数组不再是二维数组，用的是一维数组，此外新建数组用的Cpp容器，因此代码也更加简洁。