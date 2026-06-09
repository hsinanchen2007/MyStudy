### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/99fef30ced222619cb6362f11cac2af5dce028692319fdf0c5277d6b8e909dd8-image.png)

并查集介绍，其他见代码注释
https://segmentfault.com/a/1190000004023326
### 代码

```c
struct node {
    int father;
    int weight;
};

int count = 0;
int find(struct node* f, int x)
{
    while (f[x].father != x) {
        x = f[x].father;
    }
    return x;
}

void merge(int x, int y, struct node* f)
{
    int rootx = find(f, x); /* 找根节点 */
    int rooty = find(f, y); /* 找根节点 */

    if (rootx == rooty) {
        return;
    }

    if(f[x].weight > f[y].weight) { /* 按权值合并 */
        f[rooty].father = rootx;
        f[rootx].weight += f[rooty].weight;
    } else {
        f[rootx].father = rooty;
        f[rooty].weight += f[rootx].weight;
    }
    count--;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    struct node *f = (struct node*)calloc(MSize, sizeof(struct node));
    
    count = MSize; /* 初始化朋友数量为学生数量，即每个学生一个朋友圈 */
    int i;
    for (i = 0; i < MSize; i++) {
        f[i].father = i; /* 初始化各个节点的fater为自己 */
        f[i].weight = 1; /* 初始化权值为1 */
    }

    for (i = 0; i < MSize; i++) {
        for (int j = 0; j < *MColSize; j++) {
            if(i != j && M[i][j] == 1) {
                merge(i, j , f);
            }
        }
    }
    free(f);
    return count;
}
```