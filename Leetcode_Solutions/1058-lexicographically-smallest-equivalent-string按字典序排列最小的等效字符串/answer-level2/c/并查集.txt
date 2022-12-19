### 解题思路
并查集：father大的元素向father小的元素合并；
合并后更新全部元素的father，保证每个元素都能最快找到最小的father元素，保证字典序排序。

### 代码

```c
int getFather(int t, int *father)
{
    if (father[t] == t) {
        return t;
    }
    father[t] = getFather(father[t], father);
    return father[t];
}

void merge(int t1, int t2, int *father)
{
    int f1 = getFather(t1, father);
    int f2 = getFather(t2, father);
    if (f1 == f2) {
        return;
    }
    if (f1 < f2) {
        father[f2] = f1;
        father[t2] = getFather(t2, father);
    } else {
        father[f1] = f2;
        father[t1] = getFather(t1, father);
    }
}

char * smallestEquivalentString(char * A, char * B, char * S){
    if (A == NULL || B == NULL || S == NULL) {
        return NULL;
    }
    /* 定义初始化fahter数组 */
    int father[26] = {0};
    for (int i = 0; i < 26; i++) {
        father[i] = i;
    }
    /* */
    int len = strlen(A);
    for (int i = 0; i < len; i++) {
        if (A[i] < B[i]) {
            merge(A[i] - 'a', B[i] - 'a', father);
        } else {
            merge(B[i] - 'a', A[i] - 'a', father);
        }
    }
    for (int i = 0; i < 26; i++) {
        father[i] = getFather(father[i], father);
    }
    len = strlen(S);
    char *result = (char *)malloc(len + 1);
    memset(result, 0, len + 1);
    for (int i = 0; i < len; i++) {
        result[i] = father[S[i] - 'a'] + 'a';
    }
    return result;
}

```