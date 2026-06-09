### 解题思路
就是简单的hash加上qsort，题中没有标明说可以数字，稍微留意下就行了；一般的思路

### 代码

```c
#define TABNUMS 200
struct tab{
    int idx;
    int cnt;
};
int compare(const void *a, const void *b) {
    struct tab *aa = (struct tab *)a;
    struct tab *bb = (struct tab *)b;
    return  bb->cnt - aa->cnt;
}

char * frequencySort(char * s){
    struct tab hash[TABNUMS] = {0};
    int i;
    for (i = 0; i < TABNUMS; i++) {
        hash[i].idx = i;
        hash[i].cnt = 0;
    }
    char *ret = (char *)malloc(sizeof(char) * (strlen(s) + 1));


    char *tmp = s;
    while (*tmp != '\0') {

        hash[*tmp].cnt++;
        tmp++;
    }
    qsort(hash, TABNUMS, sizeof(struct tab),compare);

    int idx = 0;
    for (i=0; i < TABNUMS; i++)  {
        if (hash[i].cnt != 0) {
            for (int j = 0; j < hash[i].cnt; j++) {
                ret[idx++] = hash[i].idx;
            }
        }
    }

    ret[idx] = '\0';
    return ret;

    

}
```