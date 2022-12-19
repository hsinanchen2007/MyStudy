### 解题思路
此处撰写解题思路

排序+依次比较

### 代码

```c
int cmp(void *x, void *y)
{
    return *(char *)x - *(char *)y;
}

bool CheckPermutation(char* s1, char* s2){
    int sz1, sz2, i;
    sz1 = strlen(s1);
    sz2 = strlen(s2);

    if (sz1 != sz2) {
        return false;
    }

    if (sz1 <= 0) {
        return true;
    }

    qsort(s1, sz1, sizeof(char), cmp);
    qsort(s2, sz2, sizeof(char), cmp);

    for (i = 0; i < sz1; i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }

    return true;
}

```