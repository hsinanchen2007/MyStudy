def convert(s, numRows):
    if numRows == 1:
        return s
    numRows = min(len(s), numRows)

    s_list = ['' for i in  range(numRows)]
    res = ''
    
    # 标记方向
    goingDown = False
    # 标记当前行
    curRow = 0


    for c in s:
        s_list[curRow] += c
        if curRow == 0 or curRow == numRows - 1: goingDown = not goingDown
        curRow += 1 if goingDown else -1 
    
    for row in s_list:
        res += row
    
    return res