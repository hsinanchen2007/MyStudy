首先想到就是通过二维数据进行解答, 但是想来想去感觉构建这个二维数组是十分的麻烦，
后面看了一下官方的解答，瞬间对那个标记向上还是向下的的变量眼前一亮，原来还可以这样

```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or len(s) == 1:
            return s
        row = min(len(s), numRows)
        data = []
        for i in range(row):
            data.append([])
        go_down = True
        cur_row = 0
        for each in s:   
            data[cur_row].append(each)
            cur_row += 1 if go_down else -1
            if cur_row == 0 or cur_row == row - 1:
                go_down = False if go_down == True else True
        result_str = ""
        for each in data:
            tem_str = "".join(each)
            result_str += tem_str
        return result_str
```


执行用时 :76 ms, 在所有 python3 提交中击败了72.60% 的用户
内存消耗 :14 MB, 在所有 python3 提交中击败了7.68%的用户

执行用时 :104 ms, 在所有 python3 提交中击败了35.24% 的用户
内存消耗 :13.9 MB, 在所有 python3 提交中击败了7.93%的用户

执行用时 :80 ms, 在所有 python3 提交中击败了65.73% 的用户
内存消耗 :14 MB, 在所有 python3 提交中击败了7.68%的用户


欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)