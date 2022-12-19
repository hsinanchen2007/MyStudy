
```
def is_palindrome(s):
    s = s.strip().lower()
    length = len(s)

    if length <= 1:
        return True

    left = 0
    right = length -1
    flag = True    # 判断前假定是回文数
    while left < right:   # 如果正向索引大于等于反向索引时，则停止遍历
        if not s[left].isalnum():
            left += 1
            continue
        if not s[right].isalnum():
            right -= 1
            continue

        if s[left] == s[right]:
            left += 1
            right -= 1
        else:
            flag = False
            break

    return flag
```
