```
#define MAX_NUM 10001
#define BASE 2
int g_hash[MAX_NUM] = {0};
void InitHash(void)
{
    for (int i = 0; i < MAX_NUM; ++i) {
        g_hash[i] = 0;
    }
    return;
}
int GetMaxYueshu(int x, int y)
{
    int tmp;
    if (x < y) {
        tmp = x;
        x = y;
        y = tmp;
    }
    while (y != 0) {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}
bool hasGroupsSizeX(int* deck, int deckSize){
    int cnt = 0;
    InitHash();
    for (int i = 0; i < deckSize; ++i) {
        g_hash[deck[i]]++;
        cnt++;
    }
    int *tmpArr = (int *)calloc(cnt, sizeof(int));
    int index = 0;
    for (int i = 0; i < MAX_NUM; ++i) {
        if (g_hash[i] != 0) {
            tmpArr[index] = g_hash[i];
            index++;
        }
    }
    int yuShu = tmpArr[0];
    if (yuShu < BASE) {
        free(tmpArr);
        return false;
    }
    for (int i = 1; i < cnt; ++i) {
        yuShu = GetMaxYueshu(yuShu, tmpArr[i]);
        if (yuShu < BASE) {
            free(tmpArr);
            return false;
        }
    }
    free(tmpArr);
    return true;
}
```
