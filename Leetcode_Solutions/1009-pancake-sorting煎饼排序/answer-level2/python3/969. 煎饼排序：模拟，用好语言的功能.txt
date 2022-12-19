思路跟官解没差，就是把最大的数先转到第一个，再转到最后一个，以此类推。

但官解的Python代码，排序的应该直接reverse，匿名函数没必要，改坐标和切片操作两个比较，我认为切片逆转才算比较直观的翻煎饼模拟。

另外最好减少不必要的判断，也基本不需要剪枝，输出长度就是2n，完全符合题意。

![image.png](https://pic.leetcode-cn.com/b7c2588244dff35f59374b01d20f27f3c055103795419c8c969f14b438827d14-image.png)


```py
class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        n = len(A)
        B = sorted(A, reverse = True)       #逆序排序
        ans = []
        for i, b in enumerate(B):
            j = A.index(b) + 1              #查找当前最大值
            A[: j] = A[: j][:: -1]          #翻到最前，也可以这么写A[: j] = A[j - 1: : -1]        
            A[: n - i] = A[: n - i][:: -1]  #翻到后面，也可以这么写A[: n - i] = A[n - i - 1: : -1] 
            ans += [j, n - i]
        return ans
```
