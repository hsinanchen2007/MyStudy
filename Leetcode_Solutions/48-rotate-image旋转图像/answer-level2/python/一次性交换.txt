

## 思路:

**思路一:** 找规律

如下图所示, 图像旋转本质就是这4个数的相互交换



![1557989190734.png](https://pic.leetcode-cn.com/8dd95d925f6d79ee40be3cfe7467ad2725dd65faeef79f13458ee729675b57c5-1557989190734.png)

所以, 我们找出这几个数索引之间的关系(规律).

即:任意一个`(i,j) , (j, n-i-1), (n-i-1, n-j-1), (n -j-1, i)`就是这四个索引号上的数交换.

**思路二:** 翻转 

直接举例子:

翻转整个数组,再按正对角线交换两边的数

```
[                    [                  [
  [1,2,3],             [7,8,9],            [7,4,1],
  [4,5,6],    ---->    [4,5,6], ----->     [8,5,2],
  [7,8,9]              [1,2,3]             [9,6,3] 
]                    ]                  ]
```

这道题是顺时针的,那么逆时针呢?也是一样的


## 代码:


思路一:

```python [1]
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix) 
        for i in range(n//2):
            for j in range(i, n - i - 1):
                matrix[i][j],matrix[j][n-i-1],matrix[n-i-1][n-j-1],matrix[n-j-1][i] = \
                matrix[n-j-1][i], matrix[i][j],matrix[j][n-i-1],matrix[n-i-1][n-j-1]
        #print(matrix)
```


```java [1]
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
         for (int i = 0; i < n/2; i++ ) {
             for (int j = i; j < n - i - 1; j ++ ){
                 int tmp = matrix[i][j];
                 matrix[i][j] = matrix[n-j-1][i];
                 matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                 matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                 matrix[j][n-i-1] = tmp;
             }
         }    
    }
}
```



思路二:

```python [2]
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        matrix[:] = matrix[::-1]
        #print(matrix)
        for i in range(0, n):
            for j in range(i+1, n):
                #print(i, j)
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```



```java [2]
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // 上下翻转，两种写法
        // 第一种
        //  for (int i =0; i < n /2 ; i++ ){
        //      for (int j =0; j < n; j ++){
        //          int tmp = matrix[i][j];
        //          matrix[i][j] = matrix[n-i-1][j];
        //          matrix[n-i-1][j] = tmp;
        //      }
        //  }
        // 第二种 
        for (int i = 0; i < n / 2; i ++){
            int[] tmp = matrix[i];
            matrix[i] = matrix[n - i - 1];
            matrix[n - i - 1] = tmp;
        }
        //System.out.println(Arrays.deepToString(matrix));
        // 对角翻转
        for (int i = 0; i < n; i ++){
            for (int j= i + 1; j < n; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
}
```

