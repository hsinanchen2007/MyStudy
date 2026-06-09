### 解题思路
1. **一支笔 + 一张纸，读题并理解题目的意义**
    - **题目条件**：0 <= A.length <= 40000  0 <= A[i] < 40000 ，于是计数排序很合适 
    - **想到了计数排序的思想**，也算不错的，O(N)的复杂度就产生了
    - **把case 2 在纸张上用计数排序的思想，演示了一遍**，又发现了最终的思路
2. 演示case 2 前后，虽然都是基于 计数排序，但是思路还是有些不一样的
    - **演示前：**idx 的值 为Mi， res += Mi -1,移动到idx+1 相应的idx+1 的 Mi+1  + Mi - 1 依次类推
    - **演示后：**最终的位置 idx 累加 - 原来位置 idx 累加 即为所求结果，**相对于演示前这有点归纳的意思**
    - 当然，举这个例子，并不是为了分析演示前后哪一个方法更优，**而是说明演示过程的重要性**：
        - 演示过程中，**边界条件几乎都涉及到了**
        - **纠正脑海中的思路的不足或缺陷**

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        nsize = len(A)

        if nsize < 2:
            return 0 
        
        js = [0 for i in range(80001)]

        for ele in A:
            js[ele] += 1
        
        res = 0
        m = 0 ## 需要移动的数的个数； count基数为1的不需要移动，cnt>1 的需要移动cnt-1； 
        ## 向后遇到cnt为0的位置：m-=1; res -= idx 
        for ele, cnt in enumerate(js):
            if cnt > 1:
                res += (cnt-1) * ele 
                m += (cnt-1)
            elif cnt < 1 and m > 0:
                m -= 1
                res -= ele 
            else:
                pass 
        
        return -res 
```