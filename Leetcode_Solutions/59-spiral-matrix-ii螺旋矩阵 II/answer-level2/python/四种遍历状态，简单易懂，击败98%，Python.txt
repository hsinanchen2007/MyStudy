# 找找规律就可以发现遍历的规则是从（0，0）开始，然后j++，i++，j--，i--依次循环到结束为止，所以我们只要设置好边界条件就可以，先建立一个n*n的矩阵，元素全为0，只要下一个元素不为0，或者到达（i，j）的边界，进行状态的切换。

```javascript []
import copy
def generateMatrix(n):
    """
    :type n: int
    :rtype: List[List[int]]
    """
    total = n * n
    row = [0] * n
    res = []
    for i in range(0, n):
        c = copy.deepcopy(row)
        res.append(c)
    en = 0
    index = 2
    i = 0
    j = 0
    res[0][0] = 1
    while index < total+1:
        if en == 0:
            if j < n - 1:
                if res[i][j + 1] == 0:
                    res[i][j + 1] = index
                    j = j + 1
                    index = index + 1
                else:
                    en = 1
            else:
                en = 1
        if en == 1:
            if i < n - 1:
                if res[i + 1][j] == 0:
                    res[i + 1][j] = index
                    i = i + 1
                    index = index + 1
                else:
                    en = 2
            else:
                en = 2
        if en == 2:
            if j - 1 >= 0:
                if res[i][j - 1] == 0:
                    res[i][j - 1] = index
                    j = j - 1
                    index = index + 1
                else:
                    en = 3
            else:
                en = 3
        if en == 3:
            if i - 1 >= 0:
                print res[i - 1][j]
                if res[i - 1][j] == 0:
                    res[i - 1][j] = index
                    print "x"
                    i = i - 1
                    index = index + 1
                else:
                    en = 0
            else:
                en = 0
    return res

