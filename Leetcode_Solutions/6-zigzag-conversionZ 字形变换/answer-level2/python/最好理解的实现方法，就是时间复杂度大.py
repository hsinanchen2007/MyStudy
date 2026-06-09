def convert(s, numRows):
    """
    :type s: str
    :type numRows: int
    :rtype: str
    """
    resH = []
    l = 0
    en = True
    h = ""
    while l < len(s):
        if en == True:
            i = 0
            h = ""
            while l < len(s) and i < numRows:
                h = h + s[l]
                l = l + 1
                i = i + 1
            if len(h) > 0:
                if len(h) != numRows:
                    h = h + " " *(numRows - len(h))
                resH.append(h)
            en = False
        if en == False:
            i = 0
            h = ""
            while l < len(s) and i < numRows - 2:
                h = s[l] +h
                l = l + 1
                i = i + 1
            h = " " + h + " "
            if len(h) > 2:
                if len(h) != numRows:
                    h = " " *(numRows - len(h)) + h
                print h
                resH.append(h)
            en = True
    if len(resH[-1]) == 0:
        resH.pop(-1)
    res = ""
    print resH
    for j in range(0, len(resH[0])):
        for i in range(0, len(resH)):
            if resH[i][j] != " ":
                res= res + resH[i][j]
    return res


从图中我们可以出当numRows为n时，Z字形变换的矩阵应该是[n,n-2,n,n-2....]所以我们只要按照n和n-2的顺序进行遍历，可以得到一个Z字矩阵啦，空余位置用” “补齐，最后直接遍历输出就可以，时间复杂度较高，不过思想最简单明了。
![屏幕快照 2019-06-30 下午9.20.35.png](https://pic.leetcode-cn.com/b66ec4ce977cc4f3dfc0daf65f776ad1ba1a8d1213bed2cfa24e8d1b1d9bdbbd-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-06-30%20%E4%B8%8B%E5%8D%889.20.35.png)

