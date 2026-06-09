### 解题思路
此处撰写解题思路

### 代码

```c
int Compare(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

bool CheckPermutation(char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2) {
        return false;
    }
    qsort(s1, len1, sizeof(char), Compare);
    qsort(s2, len2, sizeof(char), Compare);
    if (strcmp(s1, s2) != 0) {
        return false;
    }
    return true;
}
```