### 思路
1. dfs
    11. 根据题意，如果这个格子摆放了棋子，那么其左右都不可以放置棋子
    12. 也就是说这行其他格子在本次都不会再选择了
    13. 所以按行来回溯
2. 状态压缩
3. 在命中的时候还原

### 详细解释
1. 使用整型中各个位来表示状态，比如一行 8 个格子，我们使用 8 位来表示是否放置棋子
    > 如： `0000 1111` 表示后 4 位都有棋子
2. 位运算：
    21. `x | y` 按位或，对每一位来说，`x` 和 `y` 中只要有一边有 1 就是 1 
    > 如： `1100 0000` | `0000 0011` --> `1100 0011`
    22. `x & y` 按位与，对每一位来说，`x` 和 `y` 中必须都是 1 才是 1
    > 如： `1100 1111` & `0011 1111` --> `0000 1111`
    23. `~x` 按位取反，对每一位来说，0 变 1， 1 变 0
    > 如： `1111 0000` --> `0000 1111`
    24. `x << n` 左移，用来将一个数的各二进制位全部左移 n 位，右补 0
    > 如： `1111 0000 << 2` --> `1100 0000` 
    25. `x >> n` 右移，用来将一个数的各二进制位全部右移 n 位，无符号数左补 0 
    > 如： `1111 0000 >> 2` --> `0011 1100` 
3. 高级位运算
    31. `x & -x` 可以将最后一位的 1 保留，其它位全部为 0
    > 如： `0000 1100` --> `0000 0100`
    32. `x & (x - 1)` 可以将最后一位 1 变成 0
    > 如： `0000 1100` --> `0000 1000`
4. 以此特点，我们可以将所有可能的棋子表示为 `1111 1111`，然后使用 `x & -x` ，选择最右边的一个
    > 如： `1111 1111` --> `0000 0001`
5. 进行计算之后，在回溯的时候，对所有可能的棋子状态使用 `x & (x - 1)`，这样就排除了本次选择的那一个
    > 如： `1111 1111` --> `1111 1110`
6. 如此循环即可将所有可能的棋子都选择进入尝试
7. 接下来在 dfs 的时候，由于已选的棋子会产生不可使用的格子，要把这个状态传进去
8. 使用 `col` 表示这一竖行
9. 使用 `ld` 和 `rd` 表示左斜和右斜，注意这个标志只表示下一行中被斜线穿过的格子
    在图形上是向左 / 右下一格，因为按行回溯，传递到下一层的是下一行的状态
    那么对于当前行选中的格子，下一行就是其向左 / 右移动的那一格
    即：`(ld | pick[row]) << 1` 和 `(rd | pick[row]) >> 1`
10. 最后，就是在命中的时候，把 `pick` 中保存的状态转换出来存成字符串

### 执行时间
![图片.png](https://pic.leetcode-cn.com/a7be8d0ef496dfa8230b1040803d3f0be25d6b792782dc0804b9c51246775dd7-%E5%9B%BE%E7%89%87.png)

### 答题
```C++ []
void dfs(int n, int row, int col, int ld, int rd, vector<int>& pick, vector<vector<string>>& ans)
{
    if (row == n)
    {
        vector<string> str(n, string(n, '.'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pick[i] & (1 << j))
                {
                    str[i][j] = 'Q';
                    break;
                }
            }
        }
        ans.push_back(str);
        return;
    }

    int pos = ~(col | ld | rd) & ((1 << n) - 1);
    while (pos != 0)
    {
        pick[row] = (pos & -pos);
        dfs(n, row + 1, (col | pick[row]), ((ld | pick[row]) << 1), ((rd | pick[row]) >> 1), pick, ans);
        pos &= (pos - 1);
    }
}

vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> ans;
    vector<int> pick(n, 0);
    dfs(n, 0, 0, 0, 0, pick, ans);
    return ans;
}
```


### 对比版本。逻辑相同，没有使用状态压缩

> 注意这个对比只是展示状态压缩之后的效率提升，如果一开始就不准备使用状态压缩，dfs不会写的这么别扭，会按照更舒服的方式回溯，也不会这么慢
> 这个代码也很形象的展示按照状态压缩的逻辑每一步在干啥，如果还不能完全理解状态压缩，可以对比查看

![图片.png](https://pic.leetcode-cn.com/3e7c495faf3d863df06c170761f864c16bc90ae602944ccebf0f2e4869617e29-%E5%9B%BE%E7%89%87.png)

```C++ []
void dfs(int n, int row, vector<int> col, vector<int> ld, vector<int> rd, vector<int>& pick, vector<vector<string>>& ans)
{
    if (row == n)
    {
        vector<string> str(n, string(n, '.'));
        for (int i = 0; i < n; i++)
        {
            str[i][pick[i]] = 'Q';
        }
        ans.push_back(str);
        return;
    }

    // int pos = ~(col | ld | rd) & ((1 << n) - 1);
    vector<int> pos(n, 0);
    for (int i = 0; i < pos.size(); i++)
    {
        pos[i] = !(col[i] == 1 || ld[i] == 1 || rd[i] == 1);
    }

    // while (pos != 0)
    while (any_of(pos.begin(), pos.end(), [](const int& a) { return a == 1; }))
    {
        // pick[row] = (pos & -pos);
        for (int i = pos.size() - 1; i >= 0; i--)
        {
            if (pos[i] != 1) continue;
            pick[row] = i;
            break;
        }

        // (col | pick[row])
        vector<int> colTemp(col);
        colTemp[pick[row]] = 1;

        // ((ld | pick[row]) << 1)
        vector<int> ldTemp(ld);
        ldTemp[pick[row]] = 1;
        for (int i = 0; i < ldTemp.size() - 1; i++)
        {
            ldTemp[i] = ldTemp[i + 1];
        }
        ldTemp.back() = 0;

        // ((rd | pick[row]) >> 1)
        vector<int> rdTemp(rd);
        rdTemp[pick[row]] = 1;
        for (int i = rdTemp.size() - 1; i > 0; i--)
        {
            rdTemp[i] = rdTemp[i - 1];
        }
        rdTemp.front() = 0;

        dfs(n, row + 1, colTemp, ldTemp, rdTemp, pick, ans);

        // pos &= (pos - 1);
        for (int i = pos.size() - 1; i >= 0; i--)
        {
            if (pos[i] != 1) continue;
            pos[i] = 0;
            break;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<int> pick(n, 0);
    dfs(n, 0, vector<int>(n, 0), vector<int>(n, 0), vector<int>(n, 0), pick, ans);
    return ans;
}
```

### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)



