这道题之前可以先做 76. 最小覆盖子串

```
def chessRight(window: dict, count: dict) -> bool:
    # 判断window中的元素是否满足count
    for count_key in count.keys():
        if window[count_key] < count[count_key]:
            return False
    return True
```

```
def balance_string(s: str) -> int:
    # 每个字母应该出现的次数
    times = int(len(s) / 4)

    count = collections.Counter()

    for val in s:
        count[val] += 1

    
    # 这里将count处理：1.不足times的元素直接删除2.多余的元素，value改为多余的次数
    for k in list(count.keys()):
        if count[k] > times:
            count[k] = count[k] - times
        else:
            del count[k]
    # 本身是平衡字符串
    if len(count) == 0:
        return 0
    # 现在count只有多余的字符  找出一个符合count的最短子字符串 （76. 最小覆盖子串）
    left = 0
    # 记录s[i:j]字符出现的次数
    window = collections.Counter()

    res = len(s) + 1
    for i in range(len(s)):
        window[s[i]] += 1
        while chessRight(window, count) and left < i + 1:
            # 符合要求, 记录长度
            res = min(res, i - left + 1)
            window[s[left]] -= 1
            left += 1
    return res
```


