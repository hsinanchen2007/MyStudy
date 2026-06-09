### 解题思路
用两个字典一个needs储存t的字母及个数，window作为滑动窗口通过check_window函数比较是否满足needs要求。使用left和right双指针，首先移动right直到check_window返回true，此时有移动右指针的解，接着移动左指针寻找最优解。当左指针最优解找到后，如果字符串长度相比res更小则存入res，左指针移动到下一位，继续移动右指针循环上述过程，直到右指针遍历完s。

### 代码

```python
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        def check_window(needs, window):
            for k in needs.keys():
                if k not in window or window.get(k, -1) < needs[k]:
                    return False
            return True
        res = ""
        if not t or len(s) < len(t):
            return ""
        left, right = 0, 0
        needs = {} #子串中需要的字母
        window = {} #当前子串有的字母
        for c in t:
            needs[c] = 1 if c not in needs else needs[c] + 1
        while right < len(s):
            window[s[right]] = 1 if s[right] not in window else window[s[right]] + 1
            while check_window(needs, window):
                #print(needs, window)
                if len(res) > len(s[left : right+1]) or not res:
                    res = s[left : right+1]
                window[s[left]] -= 1
                left += 1
                
            right += 1
        
        return res


            
        

            
```