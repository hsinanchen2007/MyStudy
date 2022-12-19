```python
def largeGroupPositions(S):
    # i, j为相同字母的开始索引, 结束索引的下一个
    r, i, j = [], 0, 0
    while j < len(S):
        # 如果字母相同, j自增
        if S[j] == S[i]:
            j += 1
            continue
        # 索引差超过3
        if j - i >= 3:
            r.append([i, j - 1])
        i = j
    # 终止条件: 相同字母在末尾
    if j - i >= 3:
        r.append([i, j - 1])
    return r

print(largeGroupPositions("abbxxxxzzy"))
print(largeGroupPositions("abc"))
print(largeGroupPositions("abcdddeeeeaabbbcd"))
print(largeGroupPositions("abccc"))
```