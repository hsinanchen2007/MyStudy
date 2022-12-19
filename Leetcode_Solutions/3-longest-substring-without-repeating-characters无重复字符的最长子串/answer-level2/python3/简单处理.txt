### 解题思路
创建一个空列表用来装不重复的子串，创建一个空字符串来装  当遇到有重复的字母时 的不重复的子串

### 代码

```python3

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        a,b = [],''
        for i in s:
            if i not in a: # 当i不在a里面
                a.append(i)
            else:
                if len(a) >= len(b):
                    b = ''.join(a)
                c = a[a.index(i)+1:]  # 取出现重复字母的那个位置的后一位'abc',i是'a'时，c='bc'
                a.clear()  # 清空a进行下一次添加
                a.extend(c)  # 把c加进去进行下一次循环
                a.append(i)  # 把i也加进去
        if len(a) > len(b): # 当最后一次不会进到else里面时，所以在这里拦截一下a是否会比b大
            b = ''.join(a)
        return len(b)
```