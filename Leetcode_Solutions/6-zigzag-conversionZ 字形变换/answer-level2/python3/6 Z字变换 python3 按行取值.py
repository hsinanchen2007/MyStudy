

 执行用时 :64 ms, 在所有 Python3 提交中击败了99.74%的用户
由题目可知 我们的最终字符串会被摆成 numRows 行,那我们理解为 最终结果是numRows个字符串相加

先建立等于numRows行数的空字符串,然后按顺序向字符串中添加字符,
核心思想是
一次完整的变换中,总共会使用 2*numRows-2个字符, 先使用了numRows个字符向下排列,即共numRows行, 每一行都按顺序加入一个字符,
然后 剩下还有 numRows-2个字符 从下往上添加入每一行,

接下来 持续用while 将整个流程包裹,完成所有字符行数变换,最后将numRows行数的各字符串拼接即可输出为答案.
```

class Solution:
    def convert(self, s, numRows):
        if not numRows > 1:
            return s
        if numRows == 2:
            s1 = s[::2]
            s2 = s[1::2]
            s3 = s1 + s2

            return s3
        s_Initialize = [''] * numRows
        # print(s_row)
        i = 0
        n = len(s)
        while i < n:
            for count_columns in range(numRows):
                if i < n:
                    s_Initialize[count_columns] += s[i]  # 这里进行了将numRows个字符从上往下安置入每一行
                    # print(s_row)
                    i += 1
            # print(s_row)
            for count_Rows in range(numRows - 2, 0, -1):  # 这里进行了将numRows-2个字符从下往上安置入每一行
                if i < n:
                    s_Initialize[count_Rows] += s[i]
                    i += 1
        return ''.join(s_Initialize)

```
