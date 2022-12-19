执行用时 :68 ms, 在所有 Python 提交中击败了100.00%的用户；
内存消耗 :11.8 MB, 在所有 Python 提交中击败了30.19%的用户。

思路非常简单，首先将原图片[sr, sc]点的值取出作为原始值。从存储待检测点的list中pop出list[0]作为待检测点，如果待检测的点有可探索的点（上下左右）且数值与原始值相同，就将改点数值改变并将该点作为一个待检测点append进list。当list为空，说明检测完成且所有符合条件点的数值都已经被替换。

def floodFill(self, image, sr, sc, newColor):
    imsize1 = len(image)
    imsize2 = len(image[0])
    num = image[sr][sc]
    if image[sr][sc] == newColor: return image
    image[sr][sc] = newColor
    changeArray = [[sr, sc]]
    while changeArray != []:
        [sr, sc] = changeArray.pop(0)
        if sc-1 >= 0:
            if image[sr][sc - 1] == num:
                image[sr][sc - 1] = newColor
                changeArray.append([sr, sc-1])
        if sr-1 >= 0:
            if image[sr - 1][sc] == num:
                image[sr - 1][sc] = newColor
                changeArray.append([sr - 1, sc])
        if sc+1 <= imsize2-1:
            if image[sr][sc + 1] == num:
                image[sr][sc + 1] = newColor
                changeArray.append([sr, sc+1])
        if sr+1 <= imsize1-1:
            if image[sr + 1][sc] == num:
                image[sr + 1][sc] = newColor
                changeArray.append([sr + 1, sc])
    return image