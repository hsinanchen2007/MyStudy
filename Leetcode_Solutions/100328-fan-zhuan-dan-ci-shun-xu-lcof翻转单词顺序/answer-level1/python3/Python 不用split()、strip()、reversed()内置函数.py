参考[https://leetcode.com/problems/reverse-words-in-a-string/discuss/172258/Python-or-Two-Pointers-%2B-No-Cheating-tm]()
```
class Solution:
    def reverseWords(self, s: str) -> str:
        def reverse_string(arr, i, j):  # 反转整个句子
            while i < j:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
                j -= 1
            return arr

        def reverse_word(arr):  # 反转单个单词
            i = j = 0
            n = len(arr)
            while i < n:
                while i < n and arr[i] == ' ':
                    i += 1
                j = i
                while j < n and arr[j] != ' ':
                    j += 1
                reverse_string(arr, i, j-1)
                i = j
            return arr

        def trim_spaces(arr):  # 去除句子两边空格
            n = len(arr)
            i, j = 0, n-1
            while i < j and arr[i] == ' ':
                i += 1
            while i < j and arr[j] == ' ':
                j -= 1
            return arr[i:j+1]
        
        def remove_spaces(arr):  # 去除句中多余空格
            if ''.join(arr) == ' ':  # 特例：' '
                return []
            res = [arr[0]]
            for i in range(1, len(arr)):
                if arr[i] == ' ' and res[-1] == ' ':
                    continue
                res.append(arr[i])
            return res

        if not s:  # 特例：''
            return ''
        arr = list(s)
        arr = reverse_string(arr, 0, len(arr)-1)
        arr = reverse_word(arr)
        arr = trim_spaces(arr)
        res = remove_spaces(arr)
        return ''.join(res)
```
