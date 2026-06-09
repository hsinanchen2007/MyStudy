class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # 设当前的字符串是 cur_str
        # 保证放下个字符后，cur_str +c 里面的( 数量 大于等于 )
        ans = list()
        def help(curr_str,a,b):
            curr_n = len(curr_str)
            # a 表示当前还可放的 ( 数量
            # b 表示当前还可放的 ) 数量
            # n - a 表示 curr_str 中有 ( 数量
            # n - b 表示 curr_str 中有 ) 数量
            if curr_n == n*2 :
                ans.append(curr_str)
                return
            if a>0:
                help(curr_str+'(',a-1,b)
            if b>0 and n - a > n - b:
                help(curr_str+')',a,b-1)
        help('',n,n)
        return ans
