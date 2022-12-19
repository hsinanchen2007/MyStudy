### 解题思路
利用双指针模拟滑动窗口，边界与滑动逻辑是重难点。

### 代码

```python3
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def isMatch(needs, count):
            for key in needs.keys():
                if count[key] < needs[key]:
                    return False
            return True

        needs = collections.defaultdict(int)
        for val in t:
            needs[val] += 1
        count = collections.defaultdict(int)
        left = 0
        length = len(s)
        while left<length:
            if s[left] in t:
                break
            left+=1
        right = left
        min_length = length + 1
        min_str = ""
        while right < length:
            # 有t的字母就加入count中
            if s[right] in t:
                count[s[right]] += 1
            # 如果找到符合要求的子串
            if isMatch(needs, count):
                # left开始滑动至下一个字母
                # 先要不满足match要求
                while isMatch(needs,count):
                    if min_length > right - left + 1:
                        min_length = right - left + 1
                        min_str = s[left:right + 1]
                    if s[left] in t:
                        count[s[left]] -= 1
                    left += 1
                # 再找到下一个最近的字符
                while left < length:
                    if s[left] in t:
                        break
                    left += 1
            if left>right:
                right=left
            else:
                right += 1
        return min_str
```