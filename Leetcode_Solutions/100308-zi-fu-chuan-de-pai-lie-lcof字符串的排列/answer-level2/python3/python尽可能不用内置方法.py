### 解题思路
1、 使用直接插入排序，将字符串排序
2、参考 leetcode 全排列II

### 代码

```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        size = len(s)
        if not size:
            return []
        s_list = [x for x in s]
        for i in range(1, size):
            temp = s_list[i]
            j = i - 1
            while j > -1 and temp < s_list[j]:
                s_list[j+1] = s_list[j]
                j -= 1
            s_list[j+1] = temp
        s = ''
        for elem in s_list:
            s += elem
        used = [False for _ in range(size)]
        result = []
        self.helper(s, size, 0, '', used, result)
        return result
    
    def helper(self, s, size, depth, path, used, result):
        if depth == size:
            result.append(path)
            return
        
        for i in range(size):
            if not used[i]:
                if i > 0 and s[i] == s[i-1] and not used[i-1]:
                    continue
                used[i] = True
                path += s[i]
                self.helper(s, size, depth+1, path, used, result)
                used[i] = False
                path = path[:-1]
```