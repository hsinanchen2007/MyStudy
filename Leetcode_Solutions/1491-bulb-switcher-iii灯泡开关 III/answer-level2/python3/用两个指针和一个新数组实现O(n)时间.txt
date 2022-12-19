维护一个新数组来记录亮灯编号，两个指针left, right分别指向最左边不亮的灯和最右边亮着的灯
只要left在right的后面，即满足条件
每次点亮一盏新的灯都让left尽可能朝后移动，每次点亮一盏灯的摊销时间为O(1)，算法总时间为O(n)
```
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
        n = len(light)
        lighton = [None] * n
        left, right = 0, 0
        count = 0
        for num in light:
            lighton[num-1] = 1
            right = max(right, num-1)
            while(left < n and lighton[left] == 1):
                left += 1
            count += left > right
        return count
```
