### 解题思路
本问题可表示为：$argmax_{k,j}(k-j)*min(a_k, a_j)$。
从底边长为$n-1$开始，递减至底边长为$1$，找出最大的。
- 当底边长为$n-1$时，仅有一种组合：$(1, n)$，其面积为$(n-1)*min(a_i, a_n)$;
- 当底边长为$n-2$时，有两种组合：
                    - $(1, n-1)$，其面积为$(n-2)*min(a_1, a_{n-1}$；
                    - $(2, n)$，其面积为$(n-2)*min(a_2, a_{n}$；
先看看，当底边长为$n-1$和$n-2$时，它们之间有一个关系：
- 如果$a_1<a_n$，那么$(n-1)*min(a_i, a_n)>min(a_1, a_{n-1}$必然成立；
- 如果$a_1>a_n$，那么$(n-1)*min(a_i, a_n)<min(a_2, a_n$必然成立。
我们发现这个规律是可以从底边长为$n-2$推到$n-3$的。
发现这个规律有什么用呢？我们在一个特定的底边长时，只需要计算一个面积，并与到目前为止发现的最大面积比较即可递减到下一底边长。

### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        mx = 0
        j = 1
        k = len(height)
        while k-j > 0:
            if height[j-1] <= height[k-1]:
                mx = max(mx, (k-j)*height[j-1])
                j += 1
            else:
                mx = max(mx, (k-j)*height[k-1])
                k -= 1
        
        return mx
```