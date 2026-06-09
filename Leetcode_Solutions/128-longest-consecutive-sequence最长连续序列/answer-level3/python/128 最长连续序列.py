### 解题思路
哈希表查询。

### 代码

```python
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        s = set(nums)
        print s
        n = len(s)
        curlen, maxlen = 1, 1
        if n == 0:
            return 0
        elif n == 1:
            return 1
        
        for num in s:
            curlen = 1
            # print num
            if (num-1) in s:
                continue
            tmp = num + 1
            while tmp in s:
                # print tmp
                tmp += 1
                curlen += 1
                maxlen = max(maxlen, curlen)

        return maxlen

```


### 解题思路
滑动窗口

### 代码

```python
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        nums.sort()
        n = len(nums)
        left = 0
        right = 0
        tmp = []
        if n == 0:
            return 0
        elif n == 1:
            return 1
        curlen, maxlen = 0, 1

        for i in range(1, n):
            if nums[i] == nums[i-1] + 1:
                right = i
            elif nums[i] == nums[i-1]:
                right = i
                tmp.append(0)
            else:
                left = i
                tmp = []
            if right > left:
                curlen = right - left + 1 - len(tmp)
                if curlen > maxlen:
                    maxlen = curlen

        return maxlen
```