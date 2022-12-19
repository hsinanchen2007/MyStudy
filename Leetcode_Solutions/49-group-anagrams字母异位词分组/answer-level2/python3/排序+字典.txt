```
def groupAnagrams(strs):
    answer = {}
    for i in range(0, len(strs)):
        # 排序
        s = "".join(sorted(strs[i]))
        # 使用字典统计
        try:
            answer[s].append(strs[i])
        except KeyError:
            answer.update({s: [strs[i]]})

    return list(answer.values())
```
