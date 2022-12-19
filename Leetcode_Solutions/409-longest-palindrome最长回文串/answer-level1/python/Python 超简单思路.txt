第一次循环，统计每种字符的个数。
第二次循环，如果该字符个数为偶数，可以直接加到回文串里来；
          如果该字符个数为奇数，把个数-1加到回文串里来，并且我们可以从这些奇数个字符中随便拿一个放到回文串里，只能是1个，所以用了flag

```python
def longestPalindrome(self, s):
    count = 0
    s_map = {}
    if len(s)==0:
        return 0
    for c in s:
        if c not in s_map:
            s_map[c] = 1
        else:
            s_map[c] += 1
    flag = False
    for k, v in s_map.items():
        if v%2==0:
            count += int(v)
        else:
            count += (v-1)
            flag = True
    return count+1 if flag else count
```
