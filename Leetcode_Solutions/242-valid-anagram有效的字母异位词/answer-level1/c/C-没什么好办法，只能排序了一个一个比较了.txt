### 解题思路
哭泣，C有字典吗

当然了排序是可以剪枝的。
这种特殊情况，size不等的话可以直接return false。
后面只能一个一个对比了

### 代码

```c
int Compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

bool isAnagram(char * s, char * t){
    if(s == NULL && t == NULL) {
        return true;
    }
    
    if(s == NULL || t == NULL) {
        return false;
    }
    
    int sSize = strlen(s);
    int tSize = strlen(t);
    
    if(sSize != tSize) {
        return false;
    }

    qsort(s, sSize, sizeof(char), Compare);
    qsort(t, tSize, sizeof(char), Compare);
    
    for(int i = 0; i < sSize; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}

```