# 储水规律解
对于一个较低的坑来说，其储水量高度取决于左侧最高柱与右侧最高柱的较小高度，因此
```
r[i] = min(max[:i+1], max[i:]) - height[i]
result = sum(r[i])
```
基本的规律解可以通过动态规划求解left_max[i], right_max[i]将时间复杂度由O(n²)优化至O(n)，此处不再赘述。重点想放在如何从动态规划解中做进一步的优化。

## 储水规律解 -- 双指针优化
在使用动态规划预计算left_max与right_max时，使用了额外的数组存储过程值，能否去掉预计算存储的过程？

假如**当前元素只依赖左侧最大值或者当前元素只依赖右侧最大值**，那么自然可以使用边遍历边计算的方法来计算left_max or right_max而无需预计算。仔细观察可以发现，计算时的确是只依赖于left_max与right_max之间的较小值。

尝试转换时可以发现，计算left_max需要顺序计算，而计算right_max需要逆序计算。单独去掉left_max和right_max数组都是比较简单的，如何能同时去掉两个数组呢？

为了能去掉两个数组，也就要求能同时计算left_max和right_max，那么为了要同时能顺序计算和逆序计算（即从两个方向一起计算），自然会想到左右双指针。但是**为了确保在计算i时能获得对应的left_max和right_max，需要额外考虑计算的顺序**。

以实例来看看应该如何考虑实际计算顺序：
```
h = [4,2,8,3,2,5]
left = 0, right = len(h) - 1 = 5, 
left_max = h[0] = 4, right_max = h[right] = 5
result = 0
```

```
left = 0, right = 5
h[left] < h[right] 说明其依赖left_max，计算left_max，result += (left_max - h[left]), left ++

left = 1, right = 5
h[left] < h[right] 说明其依赖left_max，计算left_max，result += (left_max - h[left]), left ++

left = 2, right = 5
h[left] > h[right]，说明其依赖right_max，需要从右边开始计算right_max，因此此时到右侧计算蓄水值。result += (right_max - h[right]), right--

left = 2, right = 4
h[left] > h[right]，说明其依赖right_max，需要从右边开始计算right_max，因此此时到右侧计算蓄水值。result += (right_max - h[right]), right--

left = 2, right = 3
h[left] > h[right]，说明其依赖right_max，需要从右边开始计算right_max，因此此时到右侧计算蓄水值。result += (right_max - h[right]), right--

left = 2, right = 2
h[left] == h[right]，此时会指向拥有最高高度的节点，因此left == right的情况下可以舍弃
```
对应的代码如下：
```
class Solution:
    def trap(self, height: [int]) -> int:
        if len(height) == 0:
            return 0
        
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]
        r = 0

        while left < right:
            if height[left] <= height[right]:
                if height[left] > left_max:
                    left_max = height[left]
                else:
                    r += left_max - height[left]
                left += 1

            else:
                if height[right] > right_max:
                    right_max = height[right]
                else:
                    r += right_max - height[right]
                right -= 1

        return r  
```

时间复杂度O(n)，空间复杂度O(1)
