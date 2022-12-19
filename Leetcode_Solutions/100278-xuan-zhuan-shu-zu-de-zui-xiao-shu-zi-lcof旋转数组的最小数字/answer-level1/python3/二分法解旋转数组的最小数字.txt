```
class Solution:
    def minArray(self, numbers):
        if not numbers:
            return
        #不旋转时
        if numbers[-1]>numbers[0] or len(numbers)==1:
            return numbers[0]
        #旋转时
        left = 0 #左指针
        right = len(numbers)-1 #右指针
        #当两个指针相邻时，右指针所指的数字为最小值
        while left+1 != right:
            mid  = (left +right) //2
            #特殊情况：当中间值和两端值一样时，无法判断最小值在哪个区间，比如 [10,1,10,10,10]，[10,10,10,1,10],此时只能顺序遍历，复杂度为O(n)
            if numbers[mid] == numbers[left]  and numbers[mid] == numbers[right]:
                min_num = numbers[0]
                for i in range(len(numbers)):
                    if numbers[i] < min_num:
                        min_num = numbers[i]
                return min_num
            # 中间值大于等于左边值，说明最小值在mid 和 right之间
            elif numbers[mid]>= numbers[left]:
                left = mid
            #中间值 小于左边值， 说明最小值在 left和mid之间。
            elif numbers[mid]< numbers[left]: 
                right = mid 
        return numbers[right]

```
