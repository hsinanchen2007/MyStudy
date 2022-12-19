
![0408.png](https://pic.leetcode-cn.com/41fdee2afbcebbeec894f96cf65fe9a118f807d8bd8267f2e786bc0da4859796-0408.png)

想到了色彩渲染了，没有用到什么很高级的算法。

# 思路：
1. 用一个数组m*n大小的状态数组记录每一个位置是否可达；
2. 数组中的值只有三个
    *0 不可达
    1 理论可达（行坐标和列坐标的数位之和不大于k的格子）  
    2 实际可达*
3. 两次遍历得到最终状态；

# 示例：m = 3, n = 4, k = 3

**遍历1：**根据行坐标和列坐标的数位之和，判断是否理论可达，得到如下数组

        [[1,1,1,1],
         [1,1,1,0],
         [1,1,0,0]]


**遍历2: **根据遍历1的结果，以及(0,0)实际可达，刷新数组，得到最终每个位置是否可达（有点像传染）

    刷新规则：对于每一个位置(i,j)，如果它实际可达，则它上下左右范围中理论可达的位置皆实际可达；

        [[2,2,2,2],
         [2,2,2,0],
         [2,2,0,0]]

最后一个遍历数组实际可达的位置，计算数量，得到最终结果；

```
int isReachable(int i, int j, int k) {
    if (i == 0 && j == 0) {
        return 1;
    }

    if (idSum(i, j) > k) {
        return 0;
    }

    return 1;
}

int idSum(int x, int y) { // 计算行坐标和列坐标的数位之和
    int res = 0;
    if (x >= 0 && x < 10) {
        res += x;
    } else if (x >= 10 && x < 100) {
        res += x/10 + x%10;
    } else if (x == 100) {
        res += 1;
    }

    if (y >= 0 && y < 10) {
        res += y;
    } else if (y >= 10 && y < 100) {
        res += y/10 + y%10;
    } else if (y == 100) {
        res += 1;
    }

    return res;
}

int movingCount(int m, int n, int k){
    int res = 0;
    int i;
    int j;

    int rflag[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            rflag[i][j] = isReachable(i, j ,k);  // 遍历1：理论可达
        }
    }

    rflag[0][0] = 2;

    for (i = 0; i < m; i++) {  // 遍历2：实际可达
        for (j = 0; j < n; j++) {
            if (rflag[i][j] == 2) {
                if (i-1 >= 0) { // 标记为实际可达的条件：1.理论可达 2.上下左右存在实际可达
                    rflag[i-1][j] = (rflag[i-1][j] == 1) ? 2 : rflag[i-1][j];
                }
                if (i+1 < m) {
                    rflag[i+1][j] = (rflag[i+1][j] == 1) ? 2 : rflag[i+1][j];
                }
                if (j-1 >= 0) {
                    rflag[i][j-1] = (rflag[i][j-1] == 1) ? 2 : rflag[i][j-1];
                }
                if (j+1 < n) {
                    rflag[i][j+1] = (rflag[i][j+1] == 1) ? 2 : rflag[i][j+1];
                }
            } 
        }
    } 

    for (i = 0; i < m; i++) { // 遍历2：计算实际可达个数
        for (j = 0; j < n; j++) {
            if (rflag[i][j] == 2) {
                res++;
            }
        }
    }

    return res;
}
```

方法比较粗暴，代码比较丑，先这样吧。