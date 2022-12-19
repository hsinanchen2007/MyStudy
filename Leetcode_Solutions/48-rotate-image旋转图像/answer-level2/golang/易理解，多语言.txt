# 思路
既然题目说了要原地旋转，那么就先看先旋转的规律是啥！！
对于例2中，尺寸为4：
```
00->03 03->33 33->30 30->00
01->13 13->32 32->20 20->01
02->23 23->31 31->10 10->02
03
10
11->12 12->22 22->21 21->11
12
13
20
21
22
23
30
31
32
33
```
可能这样还是没办法看出来有什么规律，那这里我总结一下：  
**对于尺寸为`n*n`的矩阵，其任意`(i, j)`点，旋转后的坐标为`(j, n - 1 - i)`。**  
从上面的例子中看出，在旋转某个节点后，某些节点也需要跟着旋转。为了避免额外的旋转操作，我们可以将矩阵进行分层：  
即从外向内，一次旋转一个正方形框，还是用例2来解释：  
第0次旋转（最外层正方形框）  
$$
\left[
\begin{matrix}
  15& 13& 2& 5 \\
  14& -& -& 1 \\
  12& -& -& 9 \\
  16& 7& 10& 11
\end{matrix}
\right]
$$
此时我们仅需要对第一行部分点`(0, 0)~(0, n-2)`(本例中`(0, 0)~(0, 2)`)进行旋转，其余点都会被带动进行旋转。  
第1次旋转（内层正方形框）  
$$
\left[
\begin{matrix}
  3& 4 \\
  6& 8
\end{matrix}
\right]
$$
此时我们仅需要对第一行部分点`(1, 1)~(1, n-3)`(本例中`(1, 1)~(1, 1)`)进行旋转，其余点都会被带动进行旋转。  
**总结规律：**
1. 对于第`k`(`k`从0开始)次旋转，每次需要旋转的节点为`(k, k)~(k, n - k - 2)`
2. 一共需要做(`n / 2`)次这样的旋转(`n`奇偶没有区别，奇数的时候，最内层正方形框只有一个元素，没必要旋转)


# 代码

## `cpp`

```cpp
// cpp没有连续赋值，需要多几个变量和多几行代码，不过do while也可以减少两行代码
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        if (1 == size) {
            return;
        } else {
            for (int i = 0; i < size / 2; i++) {
                move(matrix, i, size - 1);
            }
        }
    }

    void move(vector<vector<int>>& matrix, int s, int l) {
        // s是旋转起始位置，l是矩阵尺寸减一
        int i = s, j;
        int tmp, prev;
        for (int k = s; k < l - s; k++) {
            j = k;
            prev = matrix[i][j];
            do {
                // 计算目的点坐标
                tmp = i;
                i = j;
                j = l - tmp;
                // 保存目的点值和将当前点写入目的点
                tmp = matrix[i][j];
                matrix[i][j] = prev;
                prev = tmp;
            } while (s != i || k != j); // 如果已经旋转到起始点的目的点(可能有点绕，对于起始点是00就是0(n-1))，说明已经该点以及其带动的点已经旋转完毕
        }
    }
};
```

## `python3`
```python
# 连续赋值这时候用起来真方便，不过没有do while也是无奈
from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        size = len(matrix)
        if 1 == size:
            return
        else:
            for i in range(size // 2):
                self.move(matrix, i, size - 1)
    
    def move(self, matrix: List[List[int]], s: int, l: int) -> None:
        i, j = s, 0
        for k in range(s, l - s):
            j = k
            prev = matrix[i][j]
            i, j = j, l - i
            prev, matrix[i][j] = matrix[i][j], prev
            while s != i or k != j:
                i, j = j, l - i
                prev, matrix[i][j] = matrix[i][j], prev
```

## `go`
```go
// go的连续赋值这时候用起来真方便，不过没有do while也是无奈
func rotate(matrix [][]int)  {
	size := len(matrix)
	if 1 == size {
		return
	} else {
		for i := 0; i < size / 2; i++ {
			move(matrix, i, size - 1)
		}
	}
}

func move(matrix [][]int, s, l int)  {
	i := s
	j := 0
	for k := s; k < l - s; k++ {
		j = k
		prev := matrix[i][j]
		i, j = j, l - i
		prev, matrix[i][j] = matrix[i][j], prev
		for ; s != i || k != j; {
			i, j = j, l - i
			prev, matrix[i][j] = matrix[i][j], prev
		}
	}
}
```
![image.png](https://pic.leetcode-cn.com/b48ea542efe6c0fc1f22a0355faff84a2fa6bea77761a1bc8ba28ec6e261cf66-image.png)

# 分析
- 时间复杂度，每一个点（奇数时最内层除外）都需要操作一次，因此为$O(n^2)$
- 空间复杂度，没有使用额外的空间，因此为$O(1)$
