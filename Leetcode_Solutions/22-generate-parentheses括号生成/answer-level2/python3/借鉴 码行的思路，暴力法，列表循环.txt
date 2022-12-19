class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        '''
        1、() 一个括号
        2、()(), (())两个括号，就是在一个括号的所有位置，插入()，然后去重
        3、()()(),(())(),()(()),()(()),(()()),(()()),(())()三个括号，就是在两个括号的所有位置，插入(),然后去重
        '''
        res = {'()'}
        if n == 1:
            return res
        elif n >= 2:
            for i in range(2, n+1):
                # 每次从res取一个元素, 都会执行一遍外层循环
                res = {x[0:insert_index] + "()" + x[insert_index:] for x in res for insert_index in range(len(x))}
        return res