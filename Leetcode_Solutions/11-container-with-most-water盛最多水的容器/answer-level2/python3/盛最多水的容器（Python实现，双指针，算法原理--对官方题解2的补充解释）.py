Python实现：
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j, containMost = 0, len(height) - 1, 0

        while (i < j):
            minHeight, i, j = (height[i], i + 1, j) if height[i] < height[j] else (height[j], i, j - 1)
            containMost = max(containMost, (j - i + 1) * minHeight)

        return containMost
```


**思路**：左右边界 i,  j， 向中间收敛；左右夹逼（重要思想）
- 假设有5条线段，i左侧，j右侧

    - j < i 时讨论无意义

    - 全部组合是（i ， j）----- 也就是 枚举暴力法（蓝色代表计算有意义 的情况）
![image.png](https://pic.leetcode-cn.com/d7ecb40c9c43f293aeebeec874ecb01391d38c9f910bcd54f2cb0e31ee818b76-image.png)
 - 一边 小于等于 另一边的讨论
      - 若 i 所在边，小于等于，j所在边
        由于计算高时，高一定是height[ i ]，甚至更小，而底边长一直在缩短，则 S(1，2)、 S(1，3)、 S(1，4)  一定 小于 S(1，5)，计算他们无意义
 ![image.png](https://pic.leetcode-cn.com/79038ac361270357f9e5da506befeb5905f1e160db209c57ca5c3d08912c562d-image.png)
      - 若 j 所在边，小于， i所在边
        由于计算高时，高一定是height[ j ]，甚至更小，而底边长一直在缩短，则 S(2，5)、 S(3，5)、 S(4，5)  一定 小于 S(1，5)，计算他们无意义
![image.png](https://pic.leetcode-cn.com/e678c91affc83c04e6c0897e6c09aa61fb50032ae36c91f81485201edc5368d5-image.png)
- 同理，每计算一个面积，如上， 其对应一行或一列情况 的面积计算 无意义，直到i 与 j相遇


     
