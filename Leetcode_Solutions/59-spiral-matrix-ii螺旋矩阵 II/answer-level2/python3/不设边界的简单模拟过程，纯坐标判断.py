执行用时: 36 ms, 在所有 Python3 提交中击败了99.60%的用户

思路和前一道题解[矩阵坐标判断前进方向，不需额外数组记录](https://leetcode-cn.com/problems/spiral-matrix/solution/ju-zhen-zuo-biao-pan-duan-qian-jin-fang-xiang-bu-x/)完全一样，只是由访问变为赋值。

矩阵为m行n列，(i, j) 为当前位置坐标。

1. 设置当前访问状态（上，下，左，右），按顺序设置状态，根据状态对当前坐标进行相应加减；
2. 拐点的判断是依据当前访问所在坐标值与整个矩阵大小的关系。

不需要定义边界，完全靠坐标来判断往哪个方向走。

![59题解.jpg](https://pic.leetcode-cn.com/c38a42b39586c3486a57d8867a413fb7502c98806f0472598722172e231eba83-59%E9%A2%98%E8%A7%A3.jpg)

```
def generateMatrix(self, n: int) -> List[List[int]]:
        if n <= 0:
            return []
        if n == 1:
            return [[1]]
        
        matrix = [[0 for _ in range(n)] for _ in range(n)]
        action = {'right': (0, 1), 'down': (1, 0), 'left': (0, -1), 'up': (-1, 0)}
        count, total = 1, n*n

        i, j = 0, 0
        while count <= total:
            matrix[i][j] = count
            count += 1
            if i <= j and i+j == n-1 and act == 'right':
                act = 'down'
            elif i == j and i != 0 and act == 'down':
                act  = 'left'
            elif i > j and i+j == n-1 and act == 'left':
                act  = 'up'
            elif (i-j == 1 and act == 'up') or i == 0:
                act  = 'right'
            i += action[act][0]
            j += action[act][1]
        
        return matrix
```


时间复杂度 O(mn)
空间复杂度 O(1)

小白第一次写题解，如果有不正确的地方还请各位大佬指点！