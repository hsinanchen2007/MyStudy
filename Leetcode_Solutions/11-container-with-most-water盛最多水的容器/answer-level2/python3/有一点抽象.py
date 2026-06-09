记录下我递进写的代码
版本1：
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        length = len(height)
        if length <= 1:
            return 0

        # 选取两个高度hi,hj,i<j
        # 能储存的水的容积是 min(hi,hj) * (j-i)
        V = 0
        for i in range(0,length-1):
            for j in range(i+1,length):
                temp = min(height[i],height[j]) * (j-i)
                if temp > V:
                    V = temp

        return V
```



版本2：
```
import numpy as np
class Solution:
    def maxArea(self, height) -> int:
        length = len(height)
        if length <= 1:
            return 0

        # 返回从低到高排列的数组索引序列
        index = np.argsort(height)
        # 选取两个高度hi,hj,i<j
        # 能储存的水的容积是 min(hi,hj) * (j-i)
        # 对于hi来说，它要找的j,如果j>i,
        # 1. hj>hi,那么高度取hi,此时的j应该离i尽可能的远，
        #    即取j>i,比hi高的hj里面取j最大的
        #    从后向前扫描，if hj>=hi,得到
        # 2. hj<hi,那么高度取hj，
        #    即取j>i,比hi低的hj里面取hj * (j-i)最大的那个

        # 假设i为较高的那条边
        V = 0
        for i in range(0,length):
            k = 0
            while index[k] < length and index[k] != i and height[index[k]] <= height[i]:
                temp = height[index[k]] * abs(index[k] - i)
                if temp > V:
                    V = temp
                k += 1

        return V

```


版本3：
```
class Solution:
    def maxArea(self, height) -> int:
        length = len(height)
        if length <= 1:
            return 0

        # 选取两个高度hi,hj,i<j
        # 能储存的水的容积是 min(hi,hj) * (j-i)
        # 对于hi来说，它要找的j,如果j>i,
        # 1. hj>hi,那么高度取hi,此时的j应该离i尽可能的远，
        #    即取j>i,比hi高的hj里面取j最大的
        #    从后向前扫描，if hj>=hi,得到
        # 2. hj<hi,那么高度取hj，
        #    即取j>i,比hi低的hj里面取hj * (j-i)最大的那个

        # 假设i是较低的那条边,另一条边较高，那么只需要abs(j-i)最大
        V = 0
        mid = int( (length-1) /2) # 中线偏左
        # if i <= mid j 从length-1开始扫描
        for i in range(0,length):
            # i在中线偏左
            if i <= mid:
                for j in range(length-1,-1,-1):
                    if height[j] >= height[i] and j != i:
                        temp = height[i] * abs(j-i)
                        if temp  > V:
                            V = temp
                        break
            else:
                for j in range(0,length):
                    if height[j] >= height[i] and j != i:
                        temp = height[i] * abs(j-i)
                        if temp  > V:
                            V = temp
                        break

        return V
```



版本4：
```
class Solution:
    def maxArea(self, height) -> int:
        length = len(height)
        if length <= 1:
            return 0

        # i指向较短的线段，j指向较长的线段，面积等于height[i]*abs(j-i)
        # abs(j-i)变小，height[i]变化
        # i向j靠近导致abs(j-i)持续有变化，减小，这是一个变化因子，
        # 此时导致height[i]变化，这是一个变化结果
        # 从而导致面积变化

        i = 0
        j = length - 1
        if height[i] > height[j] :
            i = length - 1
            j = 0
        maxArea = 0
        while i != j and i >=0 and i < length:
            rect = height[i] * abs(j - i)
            if rect > maxArea: maxArea = rect
            # i指针向j指针移动一个单位
            if i < j : i += 1
            else: i -= 1
            # 此时判断哪个是新的i,哪个是新的j
            if height[i] >= height[j]:
                temp = i
                i = j
                j = temp

        return maxArea
```



版本5：
```
class Solution:
    def maxArea(self, height) -> int:
        # i指向较短的线段，j指向较长的线段，面积等于height[i]*abs(j-i)
        # abs(j-i)变小，height[i]变化
        # i向j靠近导致abs(j-i)持续有变化，减小，这是一个变化因子，
        # 此时导致height[i]变化，这是一个变化结果
        # 从而导致面积变化

        l = 0
        r = len(height) - 1
        maxArea = 0
        while l < r:
            area = min(height[l],height[r]) * abs(l-r)
            maxArea = max(area,maxArea)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return maxArea
```



版本6：
```
class Solution:
    def maxArea(self, height) -> int:
        # i指向较短的线段，j指向较长的线段，面积等于height[i]*abs(j-i)
        # abs(j-i)变小，height[i]变化
        # i向j靠近导致abs(j-i)持续有变化，减小，这是一个变化因子，
        # 此时导致height[i]变化，这是一个变化结果
        # 从而导致面积变化

        l = 0
        r = len(height) - 1
        maxArea = 0
        while l < r:
            if height[l] < height[r]:
                area = height[l] * (r-l)
                maxArea = max(area,maxArea)
                l += 1
            else:
                area = height[r] * (r-l)
                maxArea = max(area,maxArea)
                r -= 1

        return maxArea
```



但是呢，尽管写到最后一个版本，在python提交代码中还是只能击败5%的用户，sad。前好几版还都超时了，sad，必须要考虑时间复杂度。

