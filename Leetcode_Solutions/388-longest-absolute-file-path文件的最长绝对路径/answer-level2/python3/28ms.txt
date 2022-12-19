### 解题思路
通过\n对字符串分割，用\t的个数判断层级存储在一个list中 

### 代码

```python3
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        n_path = input.split('\n')
        t_str = '\t'
        path_num = []
        file_path = []
        for i in range(len(n_path)):
            num_t = n_path[i].count(t_str)
            n_path[i] = n_path[i].replace(t_str, '')
            path_num.append(num_t)

        print(n_path)

        for i in range(len(n_path)):
            if '.' in n_path[i]:
                file = n_path[i]
                p = path_num[i]
                while i > 0:
                    if path_num[i - 1] == p - 1:
                        file = n_path[i - 1] + '/' + file
                        p = p - 1
                    i -= 1
                file_path.append(file)

        if not file_path:
            return 0

        print(path_num)
        print(file_path)
        max = 0
        for i in range(len(file_path)):
            if len(file_path[i]) > max:
                max = len(file_path[i])

        return max
```