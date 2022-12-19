思路：由于每次增加斜线的长度固定，只会增加0或者1个区块，通过斜线两端点是否具有相同根即可判断是否新增区块
方法：
1. 将N*N方格按照1*1拆分， 编号
![图示.png](https://pic.leetcode-cn.com/0e13d6a901e179d0639bf0e0c5c51a526a73cf2462f8ef2f82e73603b885aba3-%E5%9B%BE%E7%A4%BA.png)
2. 初始化并查集数组，N*N边上所有点的根节点都是0
3. 遍历grid，当遇到'\\'或者'/'时判断两端点的根是否相同，如果相同说明增加线段后会新增区块 result++

```
#define MAX 1000
int g_boss[MAX];
int g_result = 0;
void init_proc(int p_num)
{
    int i;
    for(i = 0; i < p_num * p_num - 1; i++) {
        g_boss[i] = i;
    }

    for(i = 0; i < p_num; i++) {
        g_boss[i] = 0;
        g_boss[i * p_num] = 0;
        g_boss[(i + 1) * p_num - 1] = 0;
        g_boss[p_num * (p_num - 1) + i] = 0;
    }
    g_result = 1;
}
int find(int p)
{
    if (p == g_boss[p]) {
        return p;
    } else {
        g_boss[p] = find(g_boss[p]);
        return g_boss[p];
    }
}
void join(int a, int b)
{
    int boss_a = find(a);
    int boss_b = find(b);

    if (boss_a == boss_b) {
            g_result++;    
    } else {
        g_boss[boss_a] = boss_b; 
    }
    //printf("a=%d, b=%d\n", a, b); 
    //printf("boss_a=%d, boss_b=%d\n", boss_a, boss_b);
}
int regionsBySlashes(char ** grid, int gridSize){
    int i, j;
    int p;
    int p_num = gridSize + 1;
    init_proc(p_num);

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (grid[i][j] == ' ') {
                continue;
            } else if (grid[i][j] == '\\') {
                join(p_num * i + j, p_num * (i + 1) + j + 1);
            } else if (grid[i][j] == '/') {
                join(p_num * i + j + 1, p_num * (i + 1) + j);
            }
        }
    }
    return g_result;
}
```
