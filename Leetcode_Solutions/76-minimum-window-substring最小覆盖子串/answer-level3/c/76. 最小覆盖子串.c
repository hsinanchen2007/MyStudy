### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/017482615e793d53c0589838cc68952ac7d1de101eb4e9bb84776f8ba67afc3f-image.png)

### 代码

```c
#define DEBUG 0
typedef struct _node_t {
    int left;
    int right;
    int length;
}node_t;
#define MAP_SIZE (26 * 2)
typedef struct _mapNode_t {
    char key[MAP_SIZE];
    int value[MAP_SIZE];
    int times[MAP_SIZE];
    int size;
    int actNum;
    char actKeys[MAP_SIZE];
    char *t;
} mapNode_t;
mapNode_t *g_map = NULL;
int GetLetterValue(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return (int)(ch - 'a');
    } else if (ch >= 'A' && ch <= 'Z') {
        return (int)(ch - 'A' + 26);
    } else {
        return 26 * 2;
    }
}
char GetCharFormValue(int value)
{
    if (value >= 0 && value < 26) {
        return (char)('a' + value);
    } else if (value >= 26 && value < 26*2) {
        return (char)('A' + value - 26);
    } else {
        printf("<%d> the value = %d is error",__LINE__, value);
        return '\0';
    }
}
void PrintMap(mapNode_t *map)
{
    if (DEBUG != 1 || map == NULL) return;
    printf("map size = %d, act letter number in t = %d\n",map->size, map->actNum);
    for (int i = 0; i < map->size; i++) {
        if (i != 0) {
            if ( i % 13 == 0) {
                printf(",\n");
            } else {
                printf(", ");
            }
        }
        printf("%c[%d].%d",map->key[i],map->value[i],map->times[i]);
    }
    printf("\n");
}
int InitMap(mapNode_t **map, const char *t, const int tLen)
{
    *map = (mapNode_t *)malloc(sizeof(mapNode_t));
    if (*map == NULL) {
        return -1;
    }
    g_map = *map;
    (*map)->size = MAP_SIZE;
    (*map)->actNum = 0;
    (*map)->t = t;
    for (int i = 0; i < MAP_SIZE; i++) {
        (*map)->value[i] = 0;
        (*map)->key[i] = GetCharFormValue(i);
        (*map)->times[i] = 0;
        (*map)->actKeys[i] = '\0';
    }
    
    int tmp = 0;
    for (int i=0; i<tLen && t[i] != '\0'; i++) {
        tmp = GetLetterValue(t[i]);
        if (tmp == 26 * 2) {
            continue;
        }
        if (!((*map)->value[tmp])) {    // 只统计非重复的字符
            (*map)->value[tmp] = i + 1;
            (*map)->actKeys[(*map)->actNum] = t[i];
            (*map)->actNum ++;
        }
        (*map)->times[tmp]++;
    }

    return 0;
}
int DesdroyMap(mapNode_t *map)
{
    free(map);
    g_map = NULL;
    return 0;
}
int GetIndex(const mapNode_t *map, const char ch)
{
    int tmp = GetLetterValue(ch);
    return map->value[tmp];
}
int GetCntIndex(const mapNode_t *map, const char ch)
{
    int i = 0;
    for (i = 0; i < map->actNum; i++) {
        if ( ch == map->actKeys[i]) {
            return i + 1;
        }
    }
    return 0;
}
int GetTimes(const mapNode_t *map, const char ch)
{
    int tmp = GetLetterValue(ch);
    return map->times[tmp];
}
int GetActNum(const mapNode_t *map, const char ch)
{
    return map->actNum;
}
mapNode_t* GetMap()
{
    return g_map;
}
int IsCntTableOK(int *cntTable, int cntTableSize)
{
    mapNode_t* map = GetMap();
    // check if all the letter in t is exist
    int i = 0;
    for (i = 0; i < map->actNum/*cntTableSize*/; i++) {
        if (cntTable[i] < GetTimes(map, map->actKeys[i])/*1*/) {
            return false;
        }
    }
    if (i == 0) {
        return false;
    }
    return true;
}
void PrintCntTable(const int *cntTable, const char *t, int cntTableSize)
{
    if (DEBUG != 1 || cntTable == NULL) return;

    for (int i = 0; i < cntTableSize; i++) {
        if (i != 0) {
            if ( i % 10 == 0) {
                printf(",\n");
            } else {
                printf(", ");
            }
        }
        printf("%c : %d",t[i],cntTable[i]);
    }
    printf("\n");
}
int* InitCntTable(int cntTableSize)
{
    int *cntTable = (int *)malloc(sizeof(int) * cntTableSize);
    for (int i = 0; i < cntTableSize; i++) {
        cntTable[i] = 0;
    }
    return cntTable;
}

char * minWindow(char * s, char * t){
    if (s == NULL || t == NULL) return "";
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen < 1 || tLen < 1) return "";

    int *cntTable = InitCntTable(tLen);

    mapNode_t *map = NULL;
    InitMap(&map, t, tLen);
    PrintMap(map);

    //char ch = 'B';
    //printf("position[%c] = %d", ch, GetIndex(map, ch));

    int left = 0;
    int right = 0;
    int tmp = 0;

    // find the first windows
    while ( s[right] != '\0' && !IsCntTableOK(cntTable, tLen)) {
        tmp = GetCntIndex(map, s[right]);
        if (tmp) {
            cntTable[tmp-1]++;
            if (DEBUG) {
                printf("cntTable[%d] = %d\n",tmp-1, cntTable[tmp-1]);
            }
        }
        right++;
    }
    PrintCntTable(cntTable, t, tLen);

    if (!IsCntTableOK(cntTable, tLen)) {
        return "";
    }

    while (left < right /*&& !GetIndex(map, s[left])*/){
        //left++;

        tmp = GetCntIndex(map, s[left]);
        if (tmp) {
            if (cntTable[tmp -1] > GetTimes(map, s[left])/*1*/) {
                cntTable[tmp-1]--;
                left++;
            } else {
                break;
            }
        } else {
            left++;
        }
    }

    node_t ret = {0};
    ret.left = left;
    ret.right = right;
    ret.length = right - left;

    if (DEBUG) {
        printf("<%d> ret.left = %d, ret.right = %d, ret.length = %d\n", __LINE__,
            ret.left, ret.right, ret.length);
    }

    tmp = GetCntIndex(map, s[left]);
    if (tmp) {
        cntTable[tmp-1]--;
    }
    left++;
    PrintCntTable(cntTable, t, tLen);
    while (s[right] != '\0') {
        tmp = GetCntIndex(map, s[right]);
        if (tmp) {
            cntTable[tmp-1]++;
        }
        if (DEBUG) {
            printf("<%d> left = %d, right = %d\n",__LINE__, left, right);
        }
        PrintCntTable(cntTable, t, tLen);
        if (IsCntTableOK(cntTable, tLen)) {
            while (left < right){
                tmp = GetCntIndex(map, s[left]);
                if (tmp) {
                    if (cntTable[tmp -1] > GetTimes(map, s[left])/*1*/) {
                        cntTable[tmp-1]--;
                        left++;
                    } else {
                        break;
                    }
                } else {
                    left++;
                }
            }

            if (right - left + 1 < ret.length) {
                ret.left = left;
                ret.right = right;
                ret.length = right - left + 1;

                if (DEBUG) {
                    printf("<%d> ret.left = %d, ret.right = %d, ret.length = %d", __LINE__,
                        ret.left, ret.right, ret.length);
                }

                tmp = GetCntIndex(map, s[left]);
                if (tmp) {
                    cntTable[tmp-1]--;
                }
                left++;
            }
        }
        if (DEBUG) {
            printf("<%d> left = %d, right = %d\n",__LINE__, left, right);
        }
        PrintCntTable(cntTable, t, tLen);
        
        right++;
    }

    if (DEBUG) {
        printf("<%d> ret.left = %d, ret.right = %d, ret.length = %d", __LINE__,
            ret.left, ret.right, ret.length);
    }

    char *retCh = (char *)malloc(sizeof(char) * (ret.length + 1));
    int i = 0;
    for (i = 0; i < ret.length; i++) {
        retCh[i] = s[ret.left+i];
    }
    retCh[i] = '\0';

    DesdroyMap(map);
    return retCh;
}

/* test case
"ADOBECODEBANC"
"ABC"

"ADOBECODEBANC"
"A"

"ADOBECODEBANC"
"AC"

"ADOBECODEBANC"
""
"ADOBECODEBANC"
"CBA"

"ADOBECODEBBBBANCCCC"
"CBA"

"ADOBECODEBBBBAANNCCCC"
"CBA"

"ADOBECODEBBBBAANCCCC"
"CBA"

""
"CBA"

"a"
"aa"

"aa"
"aa"

"aab"
"aab"

"bba"
"ab"
*/
```