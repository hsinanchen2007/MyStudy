# dp表的定义在这里就不一一赘述了，直接上关键点
# 我第一次运行时，就把边界值处理向错了，各位可以结合别人叙述，加上我的边界处理，更为简单，别人解法都是长度加一，我的解法是在字符串前面加上空格，可以参考一下
# 在代码中关键地方进行了注释
1. 处理原始字符串，将每个字符串前面加上''
2. 处理边界值，在这里以s的长度为dp表的行数，p的长度为dp表的列数
3. 第一列不用处理，只需处理第一行的边界值：
    s[0] 为'', 对于p中的元素只有X*才能与''进行匹配，即当p[i]=='*' 则dp[0][i] = dp[0][i-1]
4. 处理非边界：
    if s[i] == p[j]： dp[i][j] = dp[i-1][j-1]
    elif p[j] == '.': dp[i][j] = dp[i-1][j-1]
    elif p[j] == '*':
        if s[i]!=p[j]: dp[i][j] = dp[i][j-2]
        else:
            dp[i][j] = (dp[i][j-2] or dp[i][j-1] or dp[i-1][j])
# 将字符串转为列表，并在列表前加上一个空字符
        s = [i for i in s]
        s.insert(0, '')
        p = [i for i in p]
        p.insert(0, '')
        m = len(s)
        n = len(p)
        # 定义dp表
        dp = [[False for _ in range(n)] for _ in range(m)]
        dp[0][0] = True
        # 处理边界 第一行
        for i in range(1, n):
            if p[i] == '*':
                dp[0][i] = dp[0][i-2]
        # 处理非边界
        for i in range(1, m):
            for j in range(1, n):
                if s[i] == p[j]:
                    dp[i][j] = dp[i-1][j-1]
                elif p[j] == '.':
                    dp[i][j] = dp[i-1][j-1]
                elif p[j] == '*':
                    if p[j-1] == s[i] or p[j-1] == '.':
                        dp[i][j] = (dp[i][j-2] or dp[i][j-1] or dp[i-1][j])
                    else:
                        dp[i][j] = dp[i][j-2] 
        return dp[-1][-1]