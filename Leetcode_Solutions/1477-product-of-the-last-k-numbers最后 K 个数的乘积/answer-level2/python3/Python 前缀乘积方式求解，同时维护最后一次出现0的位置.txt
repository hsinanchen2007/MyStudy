![image.png](https://pic.leetcode-cn.com/bb6a74da54f8cf75677c232a67627880f4fb2084021f2aa42e2c3db181a48110-image.png)



```
'''
利用前缀累积的方式维护从第一个数值到最后一个数值的乘积，
查询时候利用除法快速求区间中的数值的乘积，遇到0时候替换
成1，避免除0的异常，同时记录最后一次出现0的位置，用于
判断区间中的数值乘积是不是0
'''

class ProductOfNumbers:

    def __init__(self):
        self.mul_list = []
        self.last_zero_pos = -1

    def add(self, num: int) -> None:

        if num == 0:
            self.last_zero_pos = len(self.mul_list)
            num = 1

        if len(self.mul_list) == 0:
            self.mul_list.append(num)
        else:
            self.mul_list.append(self.mul_list[-1] * num)

    def getProduct(self, k: int) -> int:
        if self.last_zero_pos >= len(self.mul_list) - k:
            return 0

        if k == len(self.mul_list):
            return self.mul_list[-1]
        return self.mul_list[-1] // self.mul_list[-k-1]

```
