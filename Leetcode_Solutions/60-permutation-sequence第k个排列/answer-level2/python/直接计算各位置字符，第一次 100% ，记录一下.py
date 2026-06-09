
# 想法
- `k//(n-1)!`的值就是第一个位置的字符下标;
- `k//(n-1)!`的值就是下一个 k, 而pop该字符的序列既是下一个序列;
- 注意 k 是 (n-1)! 整数倍，既`k//(n-1)!`为 0 时, `(k//(n-1)!)-1`的值才是该位置的字符下标。
```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = [str(i) for i in range(1, n+1)]
        result = ''

        def func(lk):
            if not nums:
                return
            nonlocal result

            fac = 1
            for i in range(1, len(nums)):
                fac *= i
            ln = fac

            nums_index = lk // ln
            lk = lk % ln

            if lk == 0:
                nums_index -= 1

            result += nums.pop(nums_index)
            func(lk)

        func(k)
        return result
```
![屏幕快照 2019-12-03 下午2.57.35.png](https://pic.leetcode-cn.com/b5e0570a5200eb421566468f560e8d224821529337516cc01990372ae6573ecd-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-03%20%E4%B8%8B%E5%8D%882.57.35.png)

