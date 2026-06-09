逐行放置皇后，记录已经放置皇后的列、主对角线和副对角线。
```
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        answer_all = []

        # 生成棋盘
        answer = [["." for i in range(0, n)] for j in range(0, n)]

        # 记录列
        col_record = {k: 0 for k in range(0, n)}
        # 记录主对角线
        main_diagonal_record = {k: 0 for k in range(0, 2 * n - 1)}
        # 记录副对角线
        vice_diagonal_record = {k: 0 for k in range(0, 2 * n - 1)}



        def _generate(_n):
            """
            生成答案(回溯)
            :param _n当前放置的行数(从第0行开始)
            """

            # 得到一个答案
            if _n == n:
                temp = ["".join(x) for x in answer]
                answer_all.append(temp)
                return

            # 未得到答案
            for i in range(0, n):
                # 这列已经被占就跳过
                if col_record[i] != 0 or main_diagonal_record[_n + i] != 0 or vice_diagonal_record[_n + n - i - 1] != 0:
                    continue

                # 在该排的i列位置放入皇后
                answer[_n][i] = "Q"
                # 将该列置为被占
                col_record[i] = 1
                # 将所在的主对角线设置为被占
                main_diagonal_record[_n + i] = 1
                # 副对角线设置为被占
                vice_diagonal_record[_n + n - i - 1] = 1

                # 继续在下一排放入
                _generate(_n + 1)

                # 退回去
                answer[_n][i] = "."
                col_record[i] = 0
                main_diagonal_record[_n + i] = 0
                vice_diagonal_record[_n + n - i - 1] = 0



        # 生成答案
        _generate(0)

        return answer_all
```
