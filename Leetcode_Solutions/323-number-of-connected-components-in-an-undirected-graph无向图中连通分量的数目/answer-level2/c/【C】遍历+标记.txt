1. 用一个同等大小的flag数组记录边表所属阵营，对边表进行遍历：
        * 将属于同一连通分量的边表flag置为同一个值；
        * 不属于同一连通分量的边表flag置为不同值；
2. 返回flag数组中，不同值的个数。
![image.png](https://pic.leetcode-cn.com/c86c0caf6010841198fe9b568f82731c571e0ab038950ede16e7f1a7c37e844a-image.png)

```
int countComponents(int n, int** edges, int edgesSize, int* edgesColSize){
    if (n == 0 || edges == NULL || edgesSize == 0 || *edgesColSize == 0) {
        return n;
    }

    int num = n;
    int *flag = (int*)malloc(n * sizeof(int));
    if (flag == NULL) {
        return 0;
    }
    memset(flag, 0, n * sizeof(int));
    int count = 1;
    int number = count;
    flag[edges[0][0]] = count;
    flag[edges[0][1]] = count;
    n -= 2;
    for (int i = 1; i < edgesSize; i++) {
        if (flag[edges[i][0]] == 0 && flag[edges[i][1]] == 0) {
            count++;
            number++;
            flag[edges[i][0]] = count;
            flag[edges[i][1]] = count;
            n -= 2;
        } else if (flag[edges[i][0]] == 0) {
            flag[edges[i][0]] = flag[edges[i][1]];
            n -= 1;
        } else if (flag[edges[i][1]] == 0) {
            flag[edges[i][1]] = flag[edges[i][0]];
            n -= 1;
        } else if (flag[edges[i][0]] != flag[edges[i][1]]){
            int min = (flag[edges[i][0]] > flag[edges[i][1]] ? flag[edges[i][1]] : flag[edges[i][0]]);
            int max = flag[edges[i][0]] + flag[edges[i][1]] - min;

            for (int i = 0; i < num; i++) {
                if (max == flag[i]) {
                    flag[i] = min;
                }
            }
            number--;
        }
    }

    free(flag);
    return number + n;
}
```

*学习了一下先进的并查集方法，结合上面的思路，修改了一番，最快达到了16ms，看来还是需要多学习：
![image.png](https://pic.leetcode-cn.com/c013c379d01bc412c27e0a2f8e49a016830e40995ebd99b4374bf364a80a6fbc-image.png)

```
int GetParent(int *flag, int i) {
	if (i != flag[i]) {
        flag[i] = GetParent(flag, flag[i]);
    }

    return flag[i];
}

int countComponents(int n, int** edges, int edgesSize, int* edgesColSize){
    if (n == 0 || edges == NULL || edgesSize == 0 || *edgesColSize == 0) {
        return n;
    }

    int num = n;
    int *flag = (int*)malloc(n * sizeof(int));
    if (flag == NULL) {
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        flag[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) { 
        int f1 = GetParent(flag, edges[i][0]);
        int f2 = GetParent(flag, edges[i][1]);
        if (f1 == f2) {
            continue;
        }
        flag[f1] = f2;
        n--;
    }

    free(flag);
    return n;
}
```
