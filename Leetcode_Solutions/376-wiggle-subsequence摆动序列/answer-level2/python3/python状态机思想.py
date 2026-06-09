```
    def wiggleMaxLength(self, nums: List[int]) -> int:
        len_nums = len(nums)
        if len_nums <= 1: return len_nums
        #flip是状态，表示前一个数字是处在峰还是谷，ans是最终的结果，k是迭代的时候的下标
        flip, ans, k = -1,1,1
        while k < len_nums:
            if nums[k] == nums[k - 1]:
                k += 1
                continue
            f = 1 if nums[k] > nums[k - 1] else 0
            if f != flip:
                ans += 1
                flip = f
            k += 1
        return ans if ans > 0 else 1
```
其实我们只关心数组中的上下抖动就好了，不需要关心数字是几
例如：
[1, 1, 1, 17,5,10,13,15,10,5,16,8] 就是数组
[-1,-1,-1,1, 0,1, 1, 1, 0, 0,1, 0]
1代表比前一个大
0代表比前一个小
-1是开始的标志
我们设置flip初始值为-1，ans为1
原来的数组  ： [1, 1, 1, 17,5,10,13,15,10,5,16,8]
flip       ： [-1,-1,-1,1, 0,1, 1, 1, 0, 0,1, 0]
ans        ： [1, 1, 1, 2, 3,4, 4, 4, 5, 5,6, 7]
