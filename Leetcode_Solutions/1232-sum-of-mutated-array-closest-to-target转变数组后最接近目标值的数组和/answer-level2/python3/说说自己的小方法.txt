![1300.JPG](https://pic.leetcode-cn.com/3bf6debc525eabf9fa0c123471ed90a881f2526ad371c726eec065ff2773dad6-1300.JPG)

思路：
1. 总体上用的是递归的思想。先看一种最简单的情况，整数Value小于数组arr中最小的整数，此时很容易判断，value的值就是目标值target除以数组arr长度，结果四舍五入（注意这里有个坑，当小数部分为0.5时因该选择向下取整，然而round函数是向上取整，所有不能直接用round函数）。而要满足此种情况，只需要arr中最小整数乘以数组arr长度大于等于target即可。
2. 而如果arr中最小值不能满足上述情况时，说明value值大于最小值，那么在改变value值并进行求和过程中，最小值不会被改变，此时我们可以在数组中去掉此最小值，并将target值减少此最小值，则此问题就变成了一规模小一点的问题，一直递推下去，直到arr中只剩下最大值仍不能满足第一条时，很明显，这个最大值就是答案
下面上代码：
```
    def findBestValue(self, arr: List[int], target: int) -> int:
        # 首先对数组进行排序
        nums = sorted(arr)
        L = len(arr)
        i = 0
        t = target
        while i < L:
            if nums[i] * (L - i) >= t:
                res, tmp = divmod(t, (L - i))
                # 此时不能用res = t // (L - i),因为存在res 和 res + 1 谁更接近的问题
                # 也不能用round函数，前面说过，对于小数部分是0.5的情况会产生差错
                # 我选择的是求余数，看余数是否大于除数的一半，是则向上取整，结果就是res + 1
                if 2 * tmp > L - i:
                    return res + 1
                else:
                    return res
            else:
                t -= nums[i]
                i += 1           
        else:
            return nums[-1]
```

