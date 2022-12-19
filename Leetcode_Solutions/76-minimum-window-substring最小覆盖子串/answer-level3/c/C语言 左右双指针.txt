### 解题思路

![image.png](https://pic.leetcode-cn.com/a60744a0ae6aacf4a1a43b087c655335403e2b7e90828e62c99561fc081458ec-image.png)

### 代码

```c
#define MY_MATCH 1
#define MY_MISMATCH (-1)

#define MY_HASH_SIZE  128
typedef struct {
    char *s;
    int min_len;
    int min_start;
    int len;
    int start;
    int hash[MY_HASH_SIZE];
    int thash[MY_HASH_SIZE];
    int mask[MY_HASH_SIZE];
} MyStatus;
void traceS(char *tip, MyStatus *sta)
{
    char tmp;
    printf("%s : min_start=%d, min_len=%d, start=%d, s = ", tip, sta->min_start, sta->min_len, sta->start);
    tmp = sta->s[sta->start + sta->len];
    sta->s[sta->start + sta->len] = '\0';
    printf("[%s]", &sta->s[sta->start]);
    sta->s[sta->start + sta->len] = tmp;
	printf("[%s]", &sta->s[sta->start]);
    printf("\n");
}
void sInit(MyStatus *sta, char *s, char *t)
{
    sta->s = s;
    memset(sta->hash, 0, sizeof(int) * MY_HASH_SIZE);
    memset(sta->mask, 0, sizeof(int) * MY_HASH_SIZE);
    memset(sta->thash, 0, sizeof(int) * MY_HASH_SIZE);
    while (*t != '\0') {
        sta->thash[*t]++;
        sta->mask[*t] = 1;
        t++;
    }
    sta->min_len = INT_MAX;
    sta->min_start = 0;
    sta->len = 0;
    sta->start = -1; /* 这个值很关键 */
    return;
}
int cmpHash(int h1[MY_HASH_SIZE], int h2[MY_HASH_SIZE])
{
    int i, minFlag = 0;
    for(i = 0; i < MY_HASH_SIZE; i++) {
        if (h1[i] < h2[i]) { /* 有一个小就不匹配 */
			return MY_MISMATCH;
        }
    }
    /* 相等 */
    return MY_MATCH;
}
void adjustStart(MyStatus *sta, char *s, int slen, int end)
{
    int i, inx;
    int ret;
	//printf("adjustStart, sta->start = %d, end = %d\n", sta->start, end);
    /* 下面这个很关键，当第一次进入此函数时， sta->hash是包括[0, end]双闭区间的计算结果
    但是之后再进入此函数，sta->hash只包括(start, end]开闭区间的计算结果，通过把sta->start初始化为-1
    达到了这个效果*/
    for (i = sta->start + 1; i <= end; i++) {
        inx = s[i];
        sta->hash[inx]--;/* 这里会把start的字符，从sta->hash中去除 */
        sta->hash[inx] *= sta->mask[inx];
        ret = cmpHash(sta->hash, sta->thash);
        if (ret != MY_MATCH) {
			//printf("ret != MY_MATCH , i = %d\n", i);
            break;
        }
    }
    sta->start = i;
	sta->len = end - sta->start + 1;
    return;
}
void proc(MyStatus *sta, char *s, int slen)
{
    int i, inx;
    int ret;
    for (i = 0; i < slen; i++) {
        inx = s[i];
        sta->hash[inx]++;
        sta->hash[inx] *= sta->mask[inx];
        ret = cmpHash(sta->hash, sta->thash);
        if (ret != MY_MATCH) {
            continue;
        }
        if (ret == MY_MATCH) {
			//printf("ret == MY_MATCH\n");
			adjustStart(sta, s, slen, i);
            if (sta->len < sta->min_len) {
                sta->min_len = sta->len;
                sta->min_start = sta->start;
                //traceS("", sta);
            }
            continue;
        }
    }
}
char * minWindow(char * s, char * t){
    int slen, tlen;
    MyStatus sta;
    slen = strlen(s);
    tlen = strlen(t);
    if (slen == 0 || tlen == 0 || tlen > slen) {
        return "";
    }
    sInit(&sta, s, t);
    proc(&sta, s, slen);
    if (sta.min_len == INT_MAX) {
        return "";
    }
    s[sta.min_start + sta.min_len] = '\0'; 
    return &s[sta.min_start];
}
```