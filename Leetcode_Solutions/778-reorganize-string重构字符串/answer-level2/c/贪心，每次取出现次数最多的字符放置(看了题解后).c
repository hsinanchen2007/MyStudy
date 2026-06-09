### 解题思路
先对源字符串按照字符出现次数排序
按照贪心算法，每次取出现次数最多的字符放进去
### 代码

```c
//先排序，再按照贪心，每次取出现次数最多的放
#define MAX_NUM  501
#define UNIN_NUM 97
typedef struct tag {
    int cnt;
    char charactor;
} Point;
int cmp(const void *a, const void *b) {
    Point *pointa = (Point *)a;
    Point *pointb = (Point *)b;
    return pointb->cnt - pointa->cnt;
}
char * reorganizeString(char * S){
    int strLen = strlen(S);
    if (strLen == 1) { // 只有1个字符
        return S;
    }
    if (strLen == 2) {
        if (S[0] == S[1]) { return ""; }
        else { return S;}
    }
    Point *point = (Point *)malloc(sizeof(Point) * 26);
    memset(point, 0, sizeof(Point) * 26);
    for(int i = 0; i < strLen; i++) {
        char tmpChar = S[i];
        point[tmpChar - 97].cnt++;
        point[tmpChar - 97].charactor = tmpChar;
    }
    qsort(point, 26, sizeof(Point), cmp);
    //for (int i = 0; i < 26; i++) {
        //if (point[i].cnt != 0) {
            //printf("%c--%d\n", point[i].charactor, point[i].cnt);
        //}
    //}
    //printf("-----------\n");
    char *ret = (char *)calloc(strLen + 1, sizeof(char));  // 申请长度要比字符大1个，放结尾
    char lastChar = 0;
    for (int i = 0; i < strLen; i++) {
        qsort(point, 26, sizeof(Point), cmp);
        if (point[0].charactor != lastChar) { // 如果最多的和上次不同，取最多的
            ret[i] = point[0].charactor;
            point[0].cnt -= 1;
        } else { // 如果最多的和上次相同，取下一个最多的
            if (point[1].cnt == 0) { return ""; } // 如果下一个最多的已经是0了， 表示无法完成
            ret[i] = point[1].charactor;
            point[1].cnt -= 1;
        }
        lastChar = ret[i];
    }

    free(point);
    //printf("%s", ret);
    return ret;
}
```