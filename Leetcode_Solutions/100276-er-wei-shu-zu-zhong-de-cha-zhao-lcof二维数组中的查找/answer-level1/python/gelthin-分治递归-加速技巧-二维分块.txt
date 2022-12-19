### 解题思路
2020.3.13 更新字节跳动面试题。说出来从右上角搜索的思路。然后面试官问有没有其他解法，我说了一种递归的解法。面试官让我写递归的解法，但似乎 code 没有写对。 [牛课王上的 code](https://interview.***.com/interview/494021/interviewee?code=W5bJkqp2#userCode)  链接中三* 好替换为 now  and coder


```python3 
def solution_helper(A, i1, i2, j1, j2, target):
    if i1>i2 or j1>j2:
        return False
    mid_i, mid_j = i1+(i2-i1)//2, j1+(j2-j1)//2
    if A[mid_i][mid_j] == target:
        return True
    elif A[mid_i][mid_j] < target:
        # solution_helper(A, i1, mid_i, j1, mid_j)
        r1 = solution_helper(A, i1, mid_i, mid_j+1, j2)  # BUG： 缺少 target 参数
        r2 = solution_helper(A, mid_i+1, i2, j1, mid_j)
        r3 = solution_helper(A, mid_i+1, i2, mid_j+1, j2)
        return r1 or r2 or r3
    else:
        # r1 = solution_helper(A, i1, mid_i, j1, mid_j)   #搜索空间没有排除 (mid_i, mid_j), 单个元素一直在递归
        # r2 = solution_helper(A, i1, mid_i-1, mid_j+1, j2)
        # r3 = solution_helper(A, mid_i+1, i2, j1, mid_j-1)
        # Bug1: 缺少 target 参数
        # Bug2: ResursionError: 因为接下来的搜索空间没有排除 (mid_i, mid_j)单个元素一直在递归。
        # 修复 Bug2 可以打一个补丁，如果仅有一个元素准备退出

        r1 = solution_helper(A, i1, mid_i-1, j1, mid_j-1, target)  # 搜索空间不再包含任何一个冗余的元素
        r2 = solution_helper(A, i1, mid_i-1, mid_j, j2, target)
        r3 = solution_helper(A, mid_i, i2, j1, mid_j-1, target)
        return r1 or r2 or r3
    m = len(A)
    n = len(A[0])
    return solution_helper(A, target, 0, m-1, 0, n-1)
```
分块的易错点:
![图片1.png](https://pic.leetcode-cn.com/45a1318330301df7afdaf5888a0a6e080874df486e595924d9d443a29fad067e-%E5%9B%BE%E7%89%871.png)



其实不一定要分为三处，可以分为两处，也是可以的。
T(n) = T(n/4) + T(n/2) + O(1)


同习题 [240. 搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)

这题最开始想法是可以用递归，一个问题划分为 4个子问题，

每次取 mid_x, mid_y, 把整个 matrix 分为四块，

若 target > matrix[mid_x][mid_y], 则考虑左上方的那一块 （error）
若 target < matrix[mid_x][mid_y], 则考虑左下方 + 右上方 + 右下方那三块
若 target = matrix[mid_x][mid_y]，返回 True

后来发现错误，即使 target > matrix[mid_x][mid_y]， 也要考虑 左上方 + 左下方 + 右上方那一块
只能排除 1/4，即 T(n) = 3T(n/4) + O(1) => T(n) = O(n^(log_4(3)))
然后再写代码就对了。

这一题在边界条件这里卡了好久
1. 首先考虑输入是否合法，是否为空？ 
2. while(i<j) 可以在这里判断数组是否超界
3. 需要考虑 i=j 仅有一个元素时的跳出死循环
4. a1 = 0, a2= n-1, 表示 a2 仍是可取的，而不要让 a2=n, 这样 a2 不可取，造成问题。

然后如果使用 [一次遍历O(m+n)](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/yi-ci-bian-li-omn-by-erik_chen/)提供的题解，是 O(m+n), 从右上角开始搜索，当搜索到 matrix[i][j]时，若
matrix[i][j] < target, 则其所在的一列不用再考虑，若 matrix[i][j] > target, 则其所在的一行不用考虑。复杂度为 T(m,n) = max(T(m-1, n), T(m, n-1)) + O(1)  => T(m,n) = O(m+n)

[一次遍历O(m+n)](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/yi-ci-bian-li-omn-by-erik_chen/) 还提供了小技巧如下
小技巧一：把等于的情况放在大于和小于之后，因为等于是小概率事件，这样可以减少if判断次数
小技巧二：走出边界和matrix为空的判断可以统一用IndexError捕捉


### 代码 1: 递归

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        
        n = len(matrix)
        if n == 0:
            return False
        m = len(matrix[0])
        if m == 0:
            return False
        a1, a2 = 0, n-1
        b1, b2 = 0, m-1
        return subproblem(matrix, target, a1, a2, b1, b2)

def subproblem(matrix, target, a1, a2, b1, b2):
    if (a1>a2) or (b1>b2):
        return False
    if (a1 == a2) and (b1 == b2):  # 打补丁，避免下面搜索空间没有排除单个元素的情形
        if matrix[a1][b1] == target:
            return True
        else:
            return False
    mid_a = int((a1+a2)/2)
    mid_b = int((b1+b2)/2)
    if matrix[mid_a][mid_b] == target:
        return True
    elif matrix[mid_a][mid_b] > target:   
        # 这一个分支划分方式和下一个分支不一样. 后续搜索空间仍包括 （mid_i, mid_j）
        if subproblem(matrix, target, mid_a+1, a2, b1, mid_b): # 左下
            return True
        elif subproblem(matrix, target, a1, mid_a, mid_b+1, b2): #右上
            return True
        else:
            return subproblem(matrix, target, a1, mid_a, b1, mid_b)
    else: # matrix[mid_a][mid_b] < target:
        if subproblem(matrix, target, mid_a+1, a2, b1, mid_b): # 左下
            return True
        elif subproblem(matrix, target, a1, mid_a, mid_b+1, b2): #右上
            return True
        else:
            return subproblem(matrix, target, mid_a+1, a2, mid_b+1, b2)

```
``` python3 进一步修改简化的代码，可以通过。
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        
        n = len(matrix)
        if n == 0:
            return False
        m = len(matrix[0])
        if m == 0:
            return False
        a1, a2 = 0, n-1
        b1, b2 = 0, m-1
        return subproblem(matrix, target, a1, a2, b1, b2)


def subproblem(matrix, target, a1, a2, b1, b2):
    if (a1>a2) or (b1>b2):
        return False
#    if (a1 == a2) and (b1 == b2):  # 无需补丁
#        if matrix[a1][b1] == target:
#            return True
#        else:
#            return False
    mid_a = int((a1+a2)/2)
    mid_b = int((b1+b2)/2)
    if matrix[mid_a][mid_b] == target:
        return True
    elif matrix[mid_a][mid_b] > target:
        if subproblem(matrix, target, mid_a, a2, b1, mid_b-1): # 左下
            return True
        elif subproblem(matrix, target, a1, mid_a-1, mid_b, b2): #右上
            return True
        else:
            return subproblem(matrix, target, a1, mid_a-1, b1, mid_b-1)
    else: # matrix[mid_a][mid_b] < target:
        if subproblem(matrix, target, mid_a+1, a2, b1, mid_b): # 左下
            return True
        elif subproblem(matrix, target, a1, mid_a, mid_b+1, b2): #右上
            return True
        else:
            return subproblem(matrix, target, mid_a+1, a2, mid_b+1, b2)
```



### 代码 2: 从右上角开始遍历

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        if n < 1:
            return False
        m = len(matrix[0])
        s_i, s_j = 0, m-1
        while (s_i<=n-1) and (s_j>=0):
            if matrix[s_i][s_j] > target:
                s_j -= 1
            elif matrix[s_i][s_j] < target:
                s_i += 1
            else: #matrix[s_i][s_j] == target:
                return True

```