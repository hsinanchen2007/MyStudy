### 解题思路
1.按照字符长度排序字符串数组。
2.排除字符串中是否有相同的字符。
3.建立一个数组，保存符合要求的字符串。
4.挨着对比，找到有差异的进行归档。

### 代码

```c
#define LEN 16
#define MAX 26
#define MAX_NUM 450
struct strInfo {
    int len;
    char flag[MAX + 1];
};

struct strInfo g_strInfo[LEN];
int cmp(const void *a, const void *b) {
    return ((struct strInfo *)b)->len - ((struct strInfo *)a)->len;
}
//字符串内部是否存在相同的字符
int ExistInnerComm(char *a, int aSize) {
    int queue[MAX] = {0};
    int temp, i;
    for (i = 0; i < aSize; i++) {
        temp = a[i] - 'a';
        if (queue[temp]) {
            return 1;
        }
        queue[temp] = 1;
    }
    return 0;
}
//两个字符串是否有相同的字符
int ExistComm(char *a, int aSize, char *b, int bSize) {
    int i, j;
    for (i = 0; i < aSize; i++) {
        for (j = 0; j < bSize; j++) {
            if (a[i] == b[j]) {
                return 1;
            }
        }
    }

    return 0;
}

int GetMax(int *a, int aSize) {
    int max = 0;
    for (int i = 0; i < aSize; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}
int maxLength(char ** arr, int arrSize){
    int len;
    int i, j;
    int count[LEN] = {0};//包含第i个字符串的最大长度。
    int size;
    char flag[MAX_NUM];//存储合并的字符串。
    memset(g_strInfo, 0, LEN * sizeof(struct strInfo));
    for (i  = 0; i < arrSize; i++) {
        len = strlen(arr[i]);
        for (j = 0; j < len; j++) {
            g_strInfo[i].flag[g_strInfo[i].len++] = arr[i][j];
        }
        g_strInfo[i].flag[g_strInfo[i].len] = '\0';
    }
    //按长度降序排序，目的是子字符串存在相同字符时，选择长度最长的合并
    qsort(g_strInfo, arrSize, sizeof(struct strInfo), cmp);
    for (i = 0; i < arrSize; i++) {
        if (ExistInnerComm(g_strInfo[i].flag, g_strInfo[i].len)) {
            continue;
        }
        size = g_strInfo[i].len;
        strcpy(flag, g_strInfo[i].flag);
        count[i] = g_strInfo[i].len;
        for (j = 0; j < arrSize; j++) {
            if (i != j && !ExistComm(flag, size, g_strInfo[j].flag, g_strInfo[j].len) &&
            !ExistInnerComm(g_strInfo[j].flag, g_strInfo[j].len)) {
                count[i] += g_strInfo[j].len;
                strcpy(flag + size, g_strInfo[j].flag);
                size += g_strInfo[j].len;
            }
        }
    }
    return GetMax(count, LEN);
}
#if 0
char letter_map[26][2] = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};
#define MAX_LETTER_MAP_NUMBER 26
#define MAX_ARR_LENGTH 500
void init_letter_map(void) {
    int i;
    for (i = 0; i < MAX_LETTER_MAP_NUMBER; i++) {
        letter_map[i][1] = 0;
    }
    return;
}

int check_arr_is_ok(char *a) {
    int i, length1, flag1;

    length1 = strlen(a);
    init_letter_map();
    for (i = 0; i < length1; i++) {
        flag1 = a[i] - 97;
        letter_map[flag1][1]++;
    }
    for (i = 0; i < MAX_LETTER_MAP_NUMBER; i++) {
        if (letter_map[i][1] > 1) {
            printf("single letter_map[%d][0]=%c\n", i, letter_map[i][0]);
            return 0;
        }
    }

    return 1;
}

int check_two_arr_is_ok(char *a, char *b) {
    int num = 0, i;
    int length1, length2;
    int flag1, flag2, flag3 = 0;
    init_letter_map();
    length1 = strlen(a);
    length2 = strlen(b);
    for (i = 0; i < length1; i++) {
        flag1 = a[i] - 97;
        letter_map[flag1][1]++;
    }
    for (i = 0; i < length2; i++) {
        flag2 = b[i] - 97;
        letter_map[flag2][1]++;
    }
    for (i = 0; i < MAX_LETTER_MAP_NUMBER; i++) {
        if (letter_map[i][1] > 1) {
            printf("double letter_map[%d][0]=%c\n", i, letter_map[i][0]);
            return 0;
        }
    }
    return 1;
}
int cmp(const void *a, const void *b) {
    int length1, length2;
    length1 = strlen(a);
    length2 = strlen(b);
    return length1 - length2;
}
void sortBuff(char **buff,int len){//排序
    char *temp;
    int i, j;
    int length1, length2;
    for (i = 0; i < len; ++i){
        for (j = i + 1; j < len; ++j) {
            length1 = strlen(buff[i]);
            length2 = strlen(buff[j]);
            if (length1 < length2) {
                temp = buff[i];
                buff[i] = buff[j];
                buff[j] = temp;
            }
        }
    }
}
int maxLength(char ** arr, int arrSize){
    char *temparr;
    int max_num = 0, temp_num;
    int flag, flag1, flag2, length1, i;
    if (arrSize == 0) {
        return max_num;
    }
    flag = check_arr_is_ok(arr[0]);
    if (flag == 0) {
        return max_num;
    }
    length1 = strlen(arr[0]);
    if (arrSize == 1) {
        return length1;
    }
    //对ARR根据长度进行排序。
    sortBuff(arr, arrSize);
    for (i = 0; i < arrSize; i++) {
        printf("arr[%d]=%s\n", i, arr[i]);
    }
    length1 = strlen(arr[0]);
    temparr = (char *)malloc(sizeof(char) * MAX_ARR_LENGTH);
    strncpy(temparr, arr[0], length1 + 1);
    max_num = length1;
    for (i = 1; i < arrSize; i++) {
        flag1 = check_arr_is_ok(arr[i]);//检查新加入的字符串是否满足要求。
        if (flag1 == 0) {
            continue;
        }
        flag2 = check_two_arr_is_ok(temparr, arr[i]);//检查新加入的字符串跟拼接的字符串是否满足要求。
        if (flag2 == 0) {
            continue;
        }
        max_num = max_num + strlen(arr[i]);
        //把arr[i]加入到temparr中。
        printf("old temparr=%s, arr[%d]=%s\n", temparr, i, arr[i]);
        strcat(temparr, arr[i]);
        printf("new temparr=%s\n", temparr);
    }

    return max_num;
}
#endif
```