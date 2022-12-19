> 第 100 天时，我可能会对这 100 天以来的算法题进行一个总结，然后暂时停止更新 LeetCode 题解了。
下一步可能更新 NLP 相关算法了，非常感谢大家每天的支持。

## 题解
### 旋转
可以发现，每个格子旋转四次之后都会回到原位。所以对于每个格子，我们只需要交换和它相关的一共四个格子的位置就行了。

对于格子 `(i, j)` ，我们可以推算出它旋转后的三个新位置是 `(j, n-1-i), (n-1-i, n-1-j), (n-1-j, i)` 。所以只需要一个临时变量保存其中一个位置的值，然后按顺序交换位置就行了。

当然为了避免重复旋转，我们只能枚举四分之一的格子，如果 `n` 是偶数，如下图所示，我们可以这么划分：

![3.jpg](https://pic.leetcode-cn.com/65ab8303607b0f30e51e083f685bfa8a265116c2c15bedc6e6a48f2300a1603a-3.jpg)


如果 `n` 是奇数，可以如下图这么划分：

![2.jpg](https://pic.leetcode-cn.com/54730dfcbf66a2832f86177e0915276a9ca6a1341648b6484f9fa02f0da5e2c0-2.jpg)


当然你也可以不规则的划分，如下图这样，只是代码写起来有点费劲：

![1.jpg](https://pic.leetcode-cn.com/d0cc95f6113eadb8903af6c94a11de2e7d95acc3aca9085107cc16cfe0fce824-1.jpg)


### 翻转
这题还可以不通过模拟旋转来实现旋转。

上面说过了，格子 `(i, j)` 旋转后的新位置是 `(j, n-1-i)` 。

那么我们可以先沿着主对角线翻转矩阵，这样格子 `(i, j)` 位置就换到了 `(j, i)` 。

然后再左右翻转一下矩阵，格子 `(j, i)` 就换到了 `(j, n-1-i)` ，正好等价于旋转后的位置！

因为翻转每次只需要交换两个格子的位置，所以不需要任何额外变量。

再提一个交换两个元素的小 trick ，如代码里注释的那样，可以采用异或操作来规避额外变量。

## 代码
### 旋转（c++）
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < (n+1)/2; ++j) {
                int tmp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
    }
};
```

### 翻转（c++）
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                matrix[i][j] ^= matrix[j][i];
                matrix[j][i] ^= matrix[i][j];
                matrix[i][j] ^= matrix[j][i];
                // swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n/2; ++j) {
                matrix[i][j] ^= matrix[i][n-1-j];
                matrix[i][n-1-j] ^= matrix[i][j];
                matrix[i][j] ^= matrix[i][n-1-j];
                // swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};
```

### 旋转（python）
```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n//2):
            for j in range((n+1)//2):
                tmp = matrix[n-1-j][i]
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
                matrix[j][n-1-i] = matrix[i][j]
                matrix[i][j] = tmp
```

### 翻转（python）
```python
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(n):
            for j in range(n//2):
                matrix[i][j], matrix[i][n-1-j] = matrix[i][n-1-j], matrix[i][j]
```

> 关注公众号【算法码上来】，每日算法干货马上就来！
![宣传图片.jpg](https://pic.leetcode-cn.com/cdc657bd9b9e8627ccb3b789fe6f47d74ae2c0ec17673845631fd9a56a12525c-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)
