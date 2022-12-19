### 解题思路
（1）题意理解
车只能四个方向直走，只能吃掉敌人（吃掉一个便停掉），友军会挡路。
前后左右四个方向，其实是说车只能走十字，遇到一个敌人便吃掉并停下，并不会吃相邻两个敌人
因此，
第一步，需要确定车（R）在哪里，确定行raw后，再根据index索引找到R所在的十字列column
第二步，join连接十字行，形成字符串，并用('')replace替换十字行其他无用字符（'.'），形成新字符串，如果存在无阻隔的p，那么会以Rp或pR形式存在于字符串中，只要count十字行中Rp或pR数量即可
第三步，同理，找到十字列中Rp或pR数量即可
第四步，总敌人=第二步+第三步

（2）关于用到的字符串方法
index()，join()，replace()，count()等可参考链接：

https://blog.csdn.net/Chenftli/article/details/79921347?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522158519810319725222425414%2522%252C%2522scm%2522%253A%252220140713.130056874..%2522%257D&request_id=158519810319725222425414&biz_id=0&utm_source=distribute.pc_search_result.none-task


### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(len(board)):
            if 'R' in board[i]:
                raw = i
                column = board[raw].index('R')
                break
        r = ''.join(board[raw]).replace('.','')
        c = ''.join(i[column] for i in board).replace('.','')
        total_num = r.count('Rp') + r.count('pR') + c.count('Rp') + c.count('pR')
        return total_num

```