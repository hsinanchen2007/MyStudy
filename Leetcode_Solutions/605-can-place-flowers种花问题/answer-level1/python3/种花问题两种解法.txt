一、算法思想
1.不改变原数组的解法
通过计算两个1中间0的个数来计算可种植花的个数。除首尾需特殊处理外，中间两个1之间间隔3、4个0可种1棵花，5、6个0可种2棵花，以此类推。计算出可种花的个数并与n比较。
2.改变原数组的贪心算法
用变量total记录可种花个数，初始赋值为0。然后从头到尾扫描数组，如果当前位置及其前后均为0，则将当前位置元素赋值为1，相应的增加记录种植花个数的变量total，如果total等于n，则返回True，如果到最后total未达到n，则返回False。
二、算法实现
```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        # #method1
        # if n == 0:
        #     return True
        # total = 0
        # pre = -2
        # for i, num in enumerate(flowerbed):
        #     if num == 1:
        #         if i - pre > 3:
        #             total += (i - pre - 2) >> 1
        #             if total >= n:
        #                 return True
        #         pre = i
        # if len(flowerbed) - pre > 2:
        #     total += (len(flowerbed) - pre -1) >> 1
        #     if total >= n:
        #         return True
        # return False

        # method2
        if n == 0:
            return True
        total = 0
        arr_len = len(flowerbed)
        if arr_len == 0:
            return False
        if arr_len == 1:
            if flowerbed[0] == 1:
                return False
            else:
                return True
        if flowerbed[0] == 0 and flowerbed[1] == 0:
            total += 1
            if total >= n:
                return True
            flowerbed[0] = 1
        for i in range(1, arr_len - 1):
            if flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                total += 1
                if total >= n:
                    return True
                flowerbed[i] = 1
        if flowerbed[-1] == 0 and flowerbed[-2] == 0:
            total += 1
            if total >= n:
                return True
        return False
```
三、复杂度分析
两种算法的时间复杂度均为O(N)，空间复杂度均为O(1)。