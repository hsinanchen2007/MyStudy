思路：
qsort将字符数组a和b分别排序，再用strcmp(a,b)比较就好
strcmp：a = b返回0, a < b返回负数, a > b返回正数
```
int compare(const void *a, const void *b){
    return *(char*)a - *(char*)b;
}
bool isAnagram(char * s, char * t){
    qsort(s, strlen(s), sizeof(char), compare);
    qsort(t, strlen(t), sizeof(char), compare);
    return !strcmp(s, t);
}
```
