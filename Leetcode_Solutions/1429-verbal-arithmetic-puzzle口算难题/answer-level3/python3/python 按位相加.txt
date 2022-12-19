

## 思路：

模拟加法过程，从低位按位相加

代码有注释，很好理解！

```python
class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        # 找最长字符串的长度
        max_len = 0
        for word in words:
            max_len = max(max_len, len(word))

        # 如果相加的字符串长度 大于 结果的长度
        if max_len > len(result): return False
        max_len = max(max_len, len(result))
        # 重塑words,把每个字符串拉长max_len,用"#" 补齐,
        constr_words = []
        for word in words:
            constr_words.append(word.rjust(max_len, "#"))
        # 结果同样也是
        result = result.rjust(max_len, "#")
        # 按位取出
        arr = []
        for x in zip(*constr_words, result):
            arr.append(x)
        # 取反(从低位开始
        arr = arr[::-1]
        # 每个arr元素长度
        l = len(arr[0])
        # 所有数字
        all_num = set(range(10))
        # 已经使用的数字
        used_num = set()
        # 记录每个字母代表数字
        lookup = {"#": 0}

        # pos 表示到arr索引, idx 表示 arr[pos]索引, carry进位
        def dfs(pos, idx, carry):
            # 递归出口
            if pos == len(arr):
                if carry == 0:
                    return True
                else:
                    return False
            # 求在pos位是否满足条件
            if idx == l:
                tmp = 0
                for t in arr[pos][:-1]:
                    tmp += lookup[t]
                tmp += carry
                a, b = divmod(tmp, 10)
                if b != lookup[arr[pos][-1]]: return False
                return dfs(pos + 1, 0, a)
            # 判断字符串是否在lookup
            if arr[pos][idx] in lookup:
                return dfs(pos, idx + 1, carry)
            else:
                # 枚举
                for num in all_num - used_num:
                    # 保证首位不能为0
                    if ((pos + 1 < len(arr) and arr[pos + 1][idx] == "#") or pos - 1 == len(arr)) and num == 0: continue
                    used_num.add(num)
                    lookup[arr[pos][idx]] = num
                    if dfs(pos, idx + 1, carry): return True
                    lookup.pop(arr[pos][idx])
                    used_num.remove(num)
            return False

        return dfs(0, 0, 0)
```


