### 解题思路
此处撰写解题思路

### 代码

```c
#define MAXLEN 26

typedef struct
{
    int num;
    char c;
}MAP;

int Comp(const void *a, const void *b)
{
    MAP aa = *(MAP *)a;
    MAP bb = *(MAP *)b;
    return bb.num - aa.num;
}

char * reorganizeString(char * S)
{
    MAP map[MAXLEN] = {0};

    for (int i = 0; i < strlen(S); i++) {
        map[S[i] - 'a'].num++;
        map[S[i] - 'a'].c = S[i];
    }

    qsort(map, MAXLEN, sizeof(MAP), Comp);

    /* 先放偶数位 */
    int j = 0;
    int flag = 0;
    for (int i = 0; i < strlen(S); i += 2) {
        S[i] = map[j].c;
        if (--map[j].num == 0) {
            flag = 1;
            j++;
        }
    }

    if (flag == 0) {
        return "";
    }

    flag = 0;
    for (int i = 1; i < strlen(S); i += 2) {
        S[i] = map[j].c;
        if (--map[j].num == 0) {
            flag = 1;
            j++;
        }
    }

    if (flag == 0) {
        return "";
    }

    return S;
}
```