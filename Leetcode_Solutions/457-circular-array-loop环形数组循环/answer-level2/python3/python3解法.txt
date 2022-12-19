python土方法
```
class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        result = False
        for x in range(n):
            s = set()
            pos = x
            poslast = pos
            while pos not in s:
                flag = 1
                s.add(pos)
                poslast = pos
                pos += nums[pos]
                while pos > n -1:
                    pos -= n
                while pos < 0:
                    pos += n
                if nums[pos] * nums[x] < 0:
                    flag = 2
                    break
            if pos == poslast:
                continue
            if len(s) > 1 and flag == 1:
                result = True
                break
        return result
```
