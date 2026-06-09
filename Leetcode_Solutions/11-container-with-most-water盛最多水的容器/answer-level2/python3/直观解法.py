### 解题思路
两个指针i、j，分别指向数组的第一个和最后一个元素，计算出此时的值。
如果height[i] > height[j]，则指向较小值的那个指针移动，大的指针不动，一直到两个指针重逢。
随着指针的移动，不断计算出结果，最后只保存最大的即可。
### 代码

```python3
class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height) - 1
        max_num = 0

        while i < j:
            temp = (j - i) * min(height[i], height[j])
            if temp >= max_num:
                max_num = temp

            if height[i] > height[j]:
                j = j - 1
            else:
                i = i + 1

        return(max_num)
```