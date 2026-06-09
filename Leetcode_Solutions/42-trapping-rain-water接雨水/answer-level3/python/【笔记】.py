### 解题思路
思路非原创。
接完水后，最大值左侧不严格递增，右侧不严格递减。故将原数组补全以满足该条件，差值就是接水量。

1.找到height数组最大值的索引max_index（若有多个任意一个即可）
2.从两端向max_index遍历，用变量temp_max存储当前最大值
  a.当前高度height[i] < temp_max时，差值即为接水量
  b.当前高度height[i] > temp_max时，更新temp_max


### 代码

```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) == 0:
            return 0
        max_index = height.index(max(height))
        ans = 0
        temp_max = 0
        for i in range(0, max_index):
            if height[i] < temp_max:
                ans += temp_max - height[i]
            elif height[i] > temp_max:
                temp_max = height[i]
        temp_max = 0
        for i in range(len(height) - 1, max_index, -1):
            if height[i] < temp_max:
                ans += temp_max - height[i]
            elif height[i] > temp_max:
                temp_max = height[i]
        return ans

```

另外有种韦恩图解法思路也很好