``` python []
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        out_list = []
        def backtrace(n=n,left=0,right=0,s=''):
            '''
            回溯函数
            :param n: n
            :param left: 左括号的个数 
            :param right: 右括号的个数
            :param s: 字符串
            :return: 
            '''
            if len(s)==2*n:
                out_list.append(s)
                return 
            if left<n:
                backtrace(n,left+1,right,s+'(')
            if right<left:
                backtrace(n,left,right+1,s+')')
        backtrace()
        return out_list
```