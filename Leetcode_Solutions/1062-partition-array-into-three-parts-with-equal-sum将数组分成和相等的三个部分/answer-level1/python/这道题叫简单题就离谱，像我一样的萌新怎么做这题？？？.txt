![image.png](https://pic.leetcode-cn.com/e7e39cd8a588c9f4623f4d1071616911ba4ff800174ec885ea84fd3ab0d72d95-image.png)
时间复杂度$O(n)$，其中构建前缀和数组$O(n)$，双指针遍历$O(n)$。
空间复杂度$O(n)$，前缀和数组空间为$O(n)$。
要开抄的代码在最下面嗷，但是不鼓励大家直接开抄哦！
这道题我想讲讲前缀和和双指针及其优化。
首先，什么叫前缀和？
给定一个数组$A=[a_0,a_1,...,a_n]$
它的前缀和可表示为：
$S=[a_0,a_0+a_1,a_0+a_1+a_2,...,a_0+a_1+a_2+...+a_n]$
计算前缀和的时间复杂度是$O(n)$的，而不是$O(n^2)$的，这个一定要注意。
因为前缀和从第二项开始，每一项都是前缀和前面一项与原数组中对应位置元素的和，也就是：
$$
S[k]=\begin{cases}
a[0],\ when\ k=0 \\
S[k-1]+a[k],\ otherwise
\end{cases}
$$
计算完前缀和之后，我们可以想，既然要把$A$分成三部分，每部分的和相等。那么第三部分的和必然包括最后一个元素。换言之，前缀和数组的最后一个元素是整个数组的和，既然整个数组可以分成和相同的三个连续部分，那么这个和一定就是连续部分的和乘以3。所以，我们有第一个判断：
$$
若S[n]不能被3整除，那这个数组一定不能被分成和相同的三个连续不重叠部分。
$$
很好，这就刷掉一大部分情况了。剩下的情况都是有可能的。那我们接下来寻找题目中所说的$i$在哪，我们假设这个连续部分的和为$k$，那么就有$S[n]=3*k$，且$\exist i\in[0,A.length-2)$,使得$S[i]=k$。
最好的方法就是直接遍历可能的$i$，于是我们对$i$进行线性搜索，直到我们找到这样的$i$。
假设我们找到了，那么我们就要判断第二个部分的和是不是也等于$k$。因为$i+1<j$，所以我们就可以直接令$i=i+1$，开始寻找我们的$j$。
```python
def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        # 前缀和直接走了不就好了……
        # 比如[0,2,1,-6,6,-7,9,1,2,0,1]
        # 其前缀和数组为[0,2,3,-3,3,-4,5,6,8,8,9]
        # 那[3,6,9]就是一个可行的解决方案
        # 因为此题目三个部分相同，那么第一个片段和一定是target//3，那就是一个双指针问题
        # 时间复杂度O(n)，空间复杂度O(n)
        if len(A) == 0:
            return False
        sum_array = [A[0]]
        for i in range(1,len(A)):
            sum_array.append(sum_array[-1]+A[i])
        if sum_array[-1] % 3 != 0:
            return False
        i = 0
        target_l = sum_array[-1] // 3
        # 双指针优化为单指针
        while i < len(sum_array)-2: #因为第二段不能是空的
            if sum_array[i] != target_l:
                i += 1
            else:
                break
        if i == len(sum_array)-2:
            return False
        i += 1
        # 寻找第二段
        while i < len(sum_array)-1:
            if sum_array[i] != target_l*2:
                i += 1
            else:
                return True
        return False
```
