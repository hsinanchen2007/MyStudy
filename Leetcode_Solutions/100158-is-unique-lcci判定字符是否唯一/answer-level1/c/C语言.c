### 解题思路
此处撰写解题思路

方法一：使用哈希表

### 代码

```c
#define CHARNUM 256

bool isUnique(char* astr){
    int sz, i;
    int *arr = NULL;

    sz = strlen(astr);
    if (sz <= 1) {
        return true;
    }

    arr = (int *)malloc(sizeof(int) * CHARNUM);
    memset(arr, 0, sizeof(int) * CHARNUM);

    for (i = 0; i < sz; i++) {
        arr[astr[i]]++;
        if (arr[astr[i]] > 1) {
            return false;
        }
    }

    free(arr);
    return true;
}
```

方法二：排序

### 代码

```c
int cmp(void *x, void *y)
{
    return *(char *)x - *(char *)y;
}

bool isUnique(char* astr){
    int sz = 0;
    int i;
    sz = strlen(astr);
    if (sz <= 1) {
        return true;
    }

    qsort(astr, sz, sizeof(char), cmp);
    for (i = 1; i < sz; i++) {
        if (astr[i - 1] == astr[i]) {
            return false;
        }
    }

    return true;
}
```