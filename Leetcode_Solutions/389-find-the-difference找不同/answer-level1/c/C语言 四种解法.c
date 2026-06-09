### 解题思路
记录下常见的四种解法：
1. 先排序，再遍历，时间复杂度较高

```c
int comp(const void *p1,const void *p2)
{
    return strcmp(p1, p2);
}
//或者这样写比较函数
/*
void comp(const void *p1,const void *p2)
{
    return strcmp(*(char *)p1, *(char *)p2);
}
*/
char findTheDifference(char * s, char * t){
    //排序，同时遍历找不同
    int lens = strlen(s), lent = strlen(t);
    qsort(s, lens, sizeof(char), comp);
    qsort(t, lent, sizeof(char), comp);
    for(int i = 0; i < lens; i++){
        if(s[i] != t[i]) return t[i];
    }
    return t[lent - 1];
}
```
2. 数组模拟hash表：
 ```c
char findTheDifference(char * s, char * t){
    int i, lens = strlen(s), lent = strlen(t);
    int *hash = calloc(26, sizeof(int));
    for(i = 0; i < lens; i++){
        hash[s[i] - 'a']++;
    }
    for(i = 0; i < lent; i++){
        hash[t[i] - 'a']--;
    }
    for(i = 0; i < 26; i++){
        if(hash[i] == -1) return 'a' + i; 
    }
    
    return "";
}
```
3. 异或
```c
char findTheDifference(char * s, char * t){
    int sum = 0;
    while(*s != '\0'){
        sum ^= *s ^ *t;
        s++;
        t++;
    }
    return sum ^ *t;
}

```
4. 先求和再相减 
### 代码

```c
char findTheDifference(char * s, char * t){
    int sumS = 0, sumT = 0;
    while(*s != '\0'){
        sumS += *s - 'a';
        sumT += *t - 'a';
        s++;
        t++;
    }
    sumT += *t - 'a';
    return sumT - sumS + 'a';
}


```