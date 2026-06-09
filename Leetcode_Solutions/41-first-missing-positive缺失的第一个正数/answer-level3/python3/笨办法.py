想了想用了个笨办法，定义了类似数学中定义域的数据结构。

因为求最小未出现的正整数，初始定义域可以定义为。
__[1,+∞)__
然后就是遍历，每次扣出遍历值，最后剩下的域中的最小值就是答案。
O(n)<时间复杂度<O(n^2).
脑壳痛，写的有点乱，将就看吧，应该没人用我这种方法实现吧 -.-
```
class Solution:
    def firstMissingPositive(self, nums) -> int:
        if not nums: return 1
        int_set = Int_Set(1, True, float('inf'), True)
        list_set = [int_set]
        for i in nums:
            if i <= 0:
                continue
            list_set_temp = []
            for index in range(len(list_set)):
                for item in list_set[index].is_contain(i):
                    list_set_temp.append(item)
            list_set = list_set_temp
        return list_set[0].get_min()


class Int_Set:
    def __init__(self, start: int, contain_start: bool, end: int, contain_end: bool):
        self.start = [start, contain_start]
        self.end = [end, contain_end]

    # 获取域中的最小正整数
    def get_min(self):
        return self.start[0] if self.start[1] else self.start[0] + 1

    # 判断域是否包含num,如果包含，返回去除num后的集合list，如果不包含返回空数组
    def is_contain(self, num: int):
        result = []
        if num < self.start[0] or num > self.end[0]:
            result.append(self)
        elif self.start[0] < num < self.end[0]:
            if self.start[0] < num-1 and self.end[0] > num+1:
                result.append(Int_Set(self.start[0], self.start[1], num-1, True))
                result.append(Int_Set(num+1, True, self.end[0], self.end[1]))
            elif self.start[0] == num-1:
                if self.start[1]:
                    result.append(Int_Set(self.start[0], self.start[1], num, False))
                result.append(Int_Set(num + 1, True, self.end[0], self.end[1]))
            elif self.end[0] == num+1:
                result.append(Int_Set(self.start[0], self.start[1], num-1, True))
                if self.end[1]:
                    result.append(Int_Set(num, False, self.end[0], self.end[1]))
        elif self.start[0] == num:
            if num+1 < self.end[0]:
                self.start = [num+1, True]
                result.append(self)
            elif num+1 == self.end[0] and self.end[1]:
                self.start[1] = False
                result.append(self)
        elif self.end[0] == num:
            if num-1 > self.start[0]:
                self.end = [num-1, True]
                result.append(self)
            elif num-1 == self.start[0] and self.start[1]:
                self.end[1] = False
                result.append(self)
        return result
```