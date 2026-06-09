

#### 用系统函数
```python3
def reverseWords2(self, s: str) -> str:
        return " ".join(reversed(s.split()))
```

#### 双指针
1. i, j同时从字符串末尾遍历
2. j前移到第一个不为空字符的位置，如果遍历完还没有非空字符，跳到第5, 否则i跳到j所在位置，继续前移，
3. 如果字符不为空，i不断向前移动，直到字符为空，则(i+1, j)为一个单词，并把它append到res_list，j移到i的位置
4. 重复2，直到字符串遍历完毕
5. 返回' '.join(res_list)
```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        res_list = []
        i = j = len(s) - 1
        while i >= 0:
            while s[j] == ' ' and j >= 0:
                j -= 1
            if j < 0:  # 没有非空字符
                break
            i = j

            while s[i] != ' ' and i >= 0:
                i -= 1
            w = s[i+1:j+1]
            res_list.append(w)

            j = i
        return ' '.join(res_list)


```