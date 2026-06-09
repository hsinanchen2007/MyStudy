1.将容器补齐为阶梯状，计算面积
2.扣除容器部分面积

```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n <= 2: return 0
        temp = height[:]
        for i in range(1, n-1):
            temp[i] = min(max(height[: i+1]), max(height[i: ]))
        return sum(temp)-sum(height)
```
占用空间小但是重复找最大值，时间复杂度高。改进：直接把顺序最大和逆序最大用数组存储
```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n <= 2: return 0
        sum_orig = sum(height)
        l_max, r_max = height[:], height[:]
        for i in range(1, n): # maximum left->right
            l_max[i] = max(l_max[i-1], l_max[i])
        for i in range(n-2, -1, -1): # maximum right->left
            r_max[i] = max(r_max[i+1], r_max[i])

        for i in range(1, n-1):
            height[i] = min(l_max[i], r_max[i])
        return sum(height)-sum_orig
```
![image.png](https://pic.leetcode-cn.com/e53f66e2b7b85ad22640f6411e401e06151bb4e37fc09179595a7227c78c2066-image.png)


