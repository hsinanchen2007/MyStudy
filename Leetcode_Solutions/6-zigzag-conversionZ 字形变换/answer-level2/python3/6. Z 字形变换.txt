## 解题思路
    1.  列出排列
![69DEDAA9-7D4E-4407-8064-70504F2F2C6C.png](https://pic.leetcode-cn.com/29da2c85e1795bdc6e176eb80bf2d3ca39553f0286d7dc4758c04fc64aaa6dff-69DEDAA9-7D4E-4407-8064-70504F2F2C6C.png)

    2. 根据排列可知 (R0C0,R0C3), (R0C3,R0C6)之间相差6个字符（步长）即step = 2 * (numRows - 1)
    3. 列出R0C0 -> R0C3之间的字符索引计算
        
![8E4208CC-720C-49e7-BCF3-162E831A2B7F.png](https://pic.leetcode-cn.com/ca51882eefbf1737b7b54f8ef3b57cc43528b9afa4d6a33ea849210983d928f4-8E4208CC-720C-49e7-BCF3-162E831A2B7F.png)

    4. 通过分析可知 字符串s中的索引和res中索引的关系为 index = s_index % step 如果 index > max_index（最大行索引）则
       index = step - index

```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if not s or numRows <= 1:
            return s
        res = ["" for i in range(numRows)]

        step = 2 * (numRows - 1)
        max_index = numRows - 1

        for i, v in enumerate(s):
            index = i % step
            if index > max_index:
                index = step - index
            res[index] += v

        return "".join(res)
```
