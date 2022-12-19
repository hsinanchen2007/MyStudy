![image.png](https://pic.leetcode-cn.com/c480fcb857bcec5ec18eda4889c35b2a0612ccb2a3ff2e4afc981f63de87f6f8-image.png)
![image.png](https://pic.leetcode-cn.com/fb210830fee318dd6d20fd4499e29743b6a020439d94533840ce16e8dba22e8b-image.png)


思路可能会比较混乱
以matrix =  [[ 5, 1, 9,11],
             [ 2, 4, 8,10], 
              [13, 3, 6, 7],
              [15,14,12,16]]  
为例：
1. 在循环时，数组为4*4矩阵，根据题意，层层旋转指的是将矩阵由外到内一层一层地进行旋转，
   例如矩阵最外层（第0层）为[[ 5, 1, 9,11],
               [ 2, -, -,10], 
               [13, -, -, 7],
               [15,14,12,16]] 根据题意数字旋转规律为 5->11, 11->16, 16->15, 15->5; 即 5->11->16->15->5
                                                 1->10, 10->12, 12->13, 13->1; 以此类推
   该层元素共有4 - 0个，需要遍历旋转元素为4-1个，因为第4个元素在第1个元素进行变换时已经发生了变换。
   则此时在数组中为第0层，数组长度n = 4变换规律为位置在[0][0]->[0][3]->[3][3]->[3][0]; [0][1]->[1][3]->[3][3-1]->[3-1][0]; 以此类推
2. 数组第1层则为[[  -, -, -, -],
                [ -, 4, 8, -], 
                [ -, 3, 6, -],
                [ -, -, -, -]]，变换为 4->8->6->3->4,即[1][1]->[1][3-1]->[3-1][3-1]->[3-1][1]
3. 由1、2可以看出，对于len = 4的matrix，这样的存在变换价值的层共有2层，题目例子len = 3时，这样的存在变换价值的层共有1层
4. 由1、2、3可知：变换规律即第i层第j个元素变换时，[i][j]->[j][n-1-i]->[n-1-i][n-1-j]->[n-1-j][i]->[i][j]

5. 基于上述1、2、3、4陈述，总结规律为：len(matrix) = n，则这样的存在变换价值的层共有 n // 2 层
   第i层从j=i开始遍历，遍历至 n - 1 - i (减1是为了保证每一层不会遍历到最后一个，以免多变换一次)
   第i层第j个元素变换时，[i][j]->[j][n-1-i]->[n-1-i][n-1-j]->[n-1-j][i]->[i][j]
6. 代码如下：

```python []
def rotate(self, matrix: List[List[int]]) -> None:
        if len(matrix) < 2: return matrix
        n = len(matrix)
        for i in range(n // 2):
            for j in range(i, n - i - 1):
                a = matrix[i][j]
                matrix[i][j] = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
                matrix[j][n - 1 - i] = a
```
```Java []
public void rotate(int[][] matrix) {
        if(matrix.length <= 1){
            return;
        }
        int n = matrix.length;
        for(int i = 0; i < n/2; i++){
            for(int j = i; j < n-i-1; j++){
                int a = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = a;
            }
        }
    }
```

