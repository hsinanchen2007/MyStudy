# 题解
看到本题矩阵的性质，第一反应是使用两次二分查找。第一次查询，$target$的所在行。第二次查询，$target$的所在列。
## 两次二分查找
 1. 特判，若$matrix$为空或$matrix[0]$为空，主要应对$[]$和$[[]]$。
 2. 初始化矩阵行数$m$和列数$n$。
 3. 初始化查询行的左右界，$l=0$,$r=m-1$，当$l<=r$时进入循环：
 	* $mid=(l+r)//2$，若最后一行中$matrix[mid][n-1]==target$，直接返回$True$
 	* 如果$matrix[mid][n-1]>target$，令$r=mid-1$
 	* 否则，令$l=mid+1$
 4. 若查询行的左界$l>m-1$，说明$target$大于所有数组元素，返回$False$。
 5. 在$l$行内，进行搜索，初始化查询列的左右界，$l\_2=0$,$r\_2=n-1$，当$l\_2<=r\_2$时进入循环：
 	* $mid\_2=(l\_2+r\_2)//2$，在$i$行中$matrix[i][mid\_2]==target$，直接返回$True$
 	* 如果$matrix[i][mid\_2]>target$，令$r\_2=mid\_2-1$
 	* 否则，令$l\_2=mid\_2+1$。
 7. 返回$False$。

### 复杂度分析
 - 时间复杂度：$O(\log (mn))$。查找所在行$O(\log (m))$，查找所在列$O(\log (n))$ 。总体$O(\log (m))+O(\log (n))=O(\log (mn))$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if(not matrix or not matrix[0]):
            return False
        m=len(matrix)
        n=len(matrix[0])
        l=0
        r=m-1
        while(l<=r):
            mid=(l+r)//2
            if(matrix[mid][n-1]==target):
                return True
            elif(matrix[mid][n-1]>target):
                r=mid-1
            else:
                l=mid+1
        if(l>m-1):
            return False
        l_2=0
        r_2=n-1
        while(l_2<=r_2):
            mid_2=(l_2+r_2)//2
            if(matrix[l][mid_2]==target):
                return True
            elif(matrix[l][mid_2]>target):
                r_2=mid_2-1
            else:
                l_2=mid_2+1
        return False
```
## 一次二分查找
有点二维数组压缩的感觉。参考[官方题解](https://leetcode-cn.com/problems/search-a-2d-matrix/solution/sou-suo-er-wei-ju-zhen-by-leetcode/)，发现可将二维矩阵映射到一维上。图片来自官方题解。
![在这里插入图片描述](https://pic.leetcode-cn.com/dda24fb12a7bfe041f5427c31de732768867439b59177e5df77f991a18a47439.png)
由图可知，一位数组中索引为$idx$对应二维矩阵中$row$，$col$位置的元素，对应关系如下：
行        $row = idx // n$
列        $col = idx % n$

### 算法流程
1. 特判，若$matrix$为空或$matrix[0]$为空，主要应对$[]$和$[[]]$。
 2. 初始化矩阵行数$m$和列数$n$。初试化查询左右界$l=0$，$r=m*n-1$。
 3. 循环条件，当$l<=r$时进入循环：
 	 * $mid=(l+r)//2$，若$matrix[mid//n][mid\%n]==target$，直接返回$True$
 	* 如果$matrix[mid//n][mid\%n]>target$，令$r=mid-1$
 	* 否则，令$l=mid+1$
 5. 返回$False$

### 复杂度分析
 - 时间复杂度：$O(log(M*N))$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if(not matrix or not matrix[0]):
            return False
        m=len(matrix)
        n=len(matrix[0])
        l=0
        r=m*n-1
        while(l<=r):
            mid=(l+r)//2
            if(matrix[mid//n][mid%n]==target):
                return True
            elif(matrix[mid//n][mid%n]>target):
                r=mid-1
            else:
                l=mid+1
        return False
```