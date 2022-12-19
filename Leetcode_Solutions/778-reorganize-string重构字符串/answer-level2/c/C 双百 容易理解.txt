### 解题思路
此处撰写解题思路

### 代码

```c

typedef struct tagData {
    char c;
    int count;
} Data;

int compare(void *a, void *b) {
    return ((Data *)b)->count - ((Data *)a)->count;
}

void PrintData(char *S, Data *data, int count, int *index)
{
    int i;
    while (1) {
        qsort(data, count, sizeof(data), compare);
        /* 如果最多次数只需要一次，拷贝后面在数据即可 */      
        if (data[0].count == 1) {
            for (i = 0; i < count && data[i].count > 0; i++) {
                S[*index] = data[i].c;
                (*index)++;
            }            
            return;
        }
        
        /* 后面都用完了。前面还超过1个，返回空 */
        if (data[0].count > 1 && data[1].count == 0) {
            memset(S, 0, strlen(S));
            return;
        }
        
        /* 每次都循环使用个数最多的2个 */
        S[*index] = data[0].c;
        (*index)++;
        data[0].count--;
        S[*index] = data[1].c;
        (*index)++;
        data[1].count--;
    }
}

char * reorganizeString(char * S){
    if (S == NULL) {
       return NULL;
    } 
    int len = strlen(S);
    int i;
    int index = 0;
    int outCnt = 0;
    int data[26] = {0};    
    Data totalData[26] = {0};
    for(i = 0; i < len; i++) {
        data[S[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
        if (data[i] > 0) {
            totalData[index].c = i + 'a';
            totalData[index].count = data[i];
            index++;
        }
    }

    PrintData(S, totalData, index, &outCnt);    
    return S;
}
```