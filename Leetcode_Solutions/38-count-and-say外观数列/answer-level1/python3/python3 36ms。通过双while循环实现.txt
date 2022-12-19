这个题目我一开始想的也是递归，但是递归使用的不是非常熟练，所以还是用while循环来实现。我首先通过上一个项来获得下一项的值，这里就是用的get_nums()函数。

```
def output_nums(self, nums):
    index_1 = 0
    length = len(nums)
    count = 1
    new_nums = []

    while index_1 <= length - 1:
        element_1 = nums[index_1]
        index_2 = index_1 + 1

        while index_2 < length:
            if nums[index_2] == nums[index_1]:
                count += 1
                index_2 += 1
            else:       
                index_1 = index_2
                new_nums.extend([count, element_1])
                count = 1
                break
        if index_2 == length:
            new_nums.extend([count, element_1])
            break
    return new_nums
```
主要是最后几个元素不太好把握，所以单独用一个index_2 == length来去杂项。（PS: for循环用多了while就不会写了。233）

然后是迭代获得每一项的元素，也是用while实现的。
```
def recursion(self, num, nums):
    while num > 1:
        nums = self.output_nums(nums)
        num -= 1
    return nums
```

最后就是写主函数里面的内容。只要将返回的列表转换一下就好了。
```
def countAndSay(self, n: int) -> str:
        nums = self.recursion(n, [1])
        str_nums = [str(i) for i in nums]
        return ''.join(str_nums)
```

总结：这里因为for循环是根据step一步步的遍历的，不能达到跳索引的效果，所以只能用while。但是for循环平时用的太多了，导致while循环用的很不习惯，结束循环条件很不好把握，动辄死循环或者没有达到预期效果。总之，细节决定成败。以后还得多对练习。
