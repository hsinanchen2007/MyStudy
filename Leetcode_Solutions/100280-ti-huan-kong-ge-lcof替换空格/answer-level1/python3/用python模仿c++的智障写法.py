注释应该能看懂

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        # 统计有多少字符和空格
        char_num = 0
        temp_num = 0
        for elem in s:
            char_num += 1
            if elem == ' ':
                temp_num += 1
        
        # 初始化字符数组
        new_len = char_num + 2*temp_num
        s_list = ['_' for _ in range(new_len)]
        
        # 将不可变的字符串放入字符数组
        for i in range(len(s)):
            s_list[i] = s[i]
        
        # 从后往前遍历
        p1 = char_num - 1
        p2 = new_len - 1
        while p1 >= 0:
            if s_list[p1] == ' ': # 若遇到空格，则从后往前写入 %20
                s_list[p2], s_list[p2-1], s_list[p2-2] = '0', '2', '%'
                p2 -= 3
                p1 -= 1
            else:                 # 否则直接复制
                s_list[p2] = s_list[p1]
                p2 -= 1
                p1 -= 1
       
        # 将结果以字符串形式返回
        res = ''
        for elem in s_list:
            res += elem
        return res
```