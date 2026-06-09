### 解题思路
此处撰写解题思路
首先将空字符串和行数只有１的情况单独考虑；
初始化一个用来存放Ｚ型阵列的二维数组，并将字符串初始化为迭代器；
通过计算可将整个字符串分解为ｎ个循环，来存放数据；
通过堆每个循环内的字符进行位置的计算并摆放，即可得到最终的摆放阵列；
最后将阵列遍历，求解成功
### 代码

```python3
import math

class Solution:
    def convert(self, s, numRows):

        if not s:
            return ''
        if numRows ==1:
            return s
        s_length = len(s)
        # 一个循环里的成员数量
        loop_member_num = 2*numRows - 2
        # 一共包含的循环数量
        loop_num = math.ceil(s_length / loop_member_num)
        # 一个循环所占的列数
        loop_column = numRows - 1
        # 一共包含的列数
        column_num = loop_num * loop_column
        p = [[None for _ in range(column_num)] for _ in range(numRows)]
        s_iter = iter(s)
        while True:
            try:
                for i in range( loop_num):
                    start_pos = i * loop_member_num
                    start_col = i * loop_column
                    for j in range(start_pos, start_pos + loop_member_num):
                        if j < start_pos + numRows:
                            p[j % loop_member_num][start_col] = next(s_iter)
                            continue
                        start_col += 1
                        p[loop_member_num - (j % loop_member_num)][start_col] = next(s_iter)
            except StopIteration: 
                 break

        result_list = []
        for i in range(numRows):
            for j in range(column_num):
                if p[i][j]:
                    result_list.append(p[i][j])
        result = ''.join(result_list)
        return result


```