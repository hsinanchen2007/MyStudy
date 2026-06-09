因为漏了一个数，因此可以通过差值求解。先求0到n的和，再减去原数组的和，差值为所求。

        return sum([i for i in range(len(nums)+1)])-sum(nums)    