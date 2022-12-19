滑动窗口，维护最大字串长度，当字串中存在相同元素时，从最左侧开始剔除元素，即最大字串需从当前重复元素开始重新开始计算，直到遍历所有元素为止。
```
def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        left = 0
        lookup = []
        n = len(s)
        max_len = 0
        cur_len = 0
        # max_arr = [] #最大子串
        for i in range(n):
            cur_len += 1
            while s[i] in lookup:
                lookup.remove(s[left])
                left += 1
                cur_len -= 1
            lookup.append(s[i])
            if cur_len > max_len:
                max_len = cur_len
                # max_arr = lookup
        # print(max_arr)
        return max_len
```
