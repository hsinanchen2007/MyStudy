### 解题思路
执行用时 :48 ms, 在所有 Python3 提交中击败了95.38%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了6.71%的用户

思路：
因为题中要求时间复杂度为O(log(m+n))，因此想到二分法
假设i和j分别是数组A和B的分界，A左和B左小于A右和B右
1. 根据中位数的定义，由i可以算出j
2. 用二分法寻找最优的区间[p, q]，根据p和q计算目标值i
3. 得到了i和j计算最后的输出时，要考虑各种边界条件(i=0, j=0, i=m, j=n)，以及m+n是奇数还是偶数
### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, A: List[int], B: List[int]) -> float:
        if len(A) > len(B):
            A, B = B, A
        m = len(A)
        n = len(B)

        # 为了让只有一个元素的数组也能进入while循环
        # q被初始化为m而非m-1 是目标值后一个坐标
        p, q = 0, m
        # 所以p+q(即偶数长度时)为奇数时取的是后面一个数
        while p < q:
            i = (p + q) // 2
            j = (m + n + 1) // 2 - i
            if i < m and B[j - 1] > A[i]:
                # print('p++')
                p = i+1  # 注意这里是p=i+1
            elif i > 0 and A[i - 1] > B[j]:
                # print('q--')
                q = i
            else:
                # p<q的时候就已经满足条件的情况
                # 例如：A=[0, 2], B=[1, 3]
                break
        # 达到最优时候跳出的left和right计算i
        # 此处进入不是最优才会进入if或者elif 所以p q直接用就行 不需要p-1之类得操作
        i = (p + q) // 2
        j = (m + n + 1) // 2 - i
        # print('final i, j:', i, j)

        # 找到了i返回结果
        if i == 0:
            l_max = B[j-1]
        elif j == 0:
            l_max = A[i - 1]
        else:
            l_max = max(A[i-1], B[j-1])

        # 当m+n时奇数的时候，输出只与l_max有关
        # 所以先计算l_max 在这里加一个if ...: return ...提高计算效率
        if (m + n) % 2 == 1:
            return l_max

        if i == m:
            r_min = B[j]
        elif j == n:
            r_min = A[i]
        else:
            r_min = min(A[i], B[j])

        return (l_max + r_min) / 2

```