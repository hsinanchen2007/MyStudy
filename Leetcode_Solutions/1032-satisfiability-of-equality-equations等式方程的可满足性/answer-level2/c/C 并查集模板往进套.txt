用并查集来做，网上找了个很好理解的讲义，大家可以看看。
https://blog.csdn.net/liujian20150808/article/details/50848646

```
int pre[26] = {0};
/* 查找根节点函数 */
int find(int x) {
    int r = x;
    while (pre[r] != r) {
        r = pre[r];
    }
    /* 路径压缩 */
    int i = x;
    int j;
    while (i != r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

/* 判断x, y是否连通 */
void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    /* 如果已经连通,就不用管了,如果不连通,就把它们所在的连通分支合并起来. */
    if (fx != fy) {
        pre[fx] = fy;
    }
}

bool equationsPossible(char ** equations, int equationsSize){
    int flag = true;

    /* 并查集存放父节点数组初始化 */
    for (int i = 0; i < 26; i++) {
        pre[i] = i;
    }

    for (int j = 0; j < equationsSize; j++) {
        if (equations[j][1] == '=') {
            join(equations[j][0] - 'a', equations[j][3] - 'a');
        }
    }

    for (int k = 0; k < equationsSize; k++) {
        if (equations[k][1] == '!') {
            int x = find(equations[k][0] - 'a');
            int y = find(equations[k][3] - 'a');
            if (x == y) {
                flag = false;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        pre[i] = 0;
    }
    return flag;
}
```
