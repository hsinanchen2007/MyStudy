### 解题思路
通过题目条件可知字符串只能包含26个小写字母，因此可以利用一个unsigned int来映射子字符串。
两个字符串str[i]和str[j]是否有重复的字母，可以直接通过判断str[i] & str[j] != 0来实现。
求解最大的字符串长度的过程，就可以转换为一个类似广搜的过程。
从第一个字符串开始，不断的尝试将新的子字符串和队列中已有的字符串进行组合，新组合字母不重复，就新增到队列尾（记得子字符串本身也是一个组合），在扩展的过程中，不断更新最大长度。
所有的扩展完成后，就可以直接返回最大长度了。

### 代码

```c
// 将字符串映射为unsigned int的队列成员定义
typedef struct OneStrHashType{
    unsigned int hash;
    unsigned char len;
    struct OneStrHashType *next;
}OneStrHash;

// 将字符串映射为unsigned int
unsigned int StrToU32(char *str)
{
    unsigned int ret = 0;
    unsigned int shift = 0;

    while(*str != '\0') {
        shift = 1<<(unsigned char)((*str) - 'a');
        if ((ret & shift) != 0) {
            return 0;
        }
        ret |= shift;
        str++;
    }
    return ret;
}

// 计算unsigned int中1的数目
unsigned char CountLen(unsigned int value) 
{
    unsigned char ret = 0;
    while(value != 0) {
        ret += (value & 1);
        value = value>> 1;
    }
    return ret;
}

int maxLength(char ** arr, int arrSize){
    // 计算子字符串的映射及长度时的空间
    unsigned int *table = malloc(sizeof(unsigned int)*arrSize);
    unsigned char *lenTable = malloc(sizeof(unsigned char)*arrSize);
    int i;
    int begin = 0;
    int maxLen = 0;
    int count = 0;
    OneStrHash *head = NULL;
    OneStrHash *tail = NULL;
    OneStrHash *newHead = NULL;
    OneStrHash *newTail = NULL;
    OneStrHash *tempP = NULL;

    // 计算子字符串本身的映射及1的数目
    for (i=0; i<arrSize; i++) {
        table[i] = StrToU32(arr[i]);
        lenTable[i] = CountLen(table[i]);
        if (lenTable[i] > maxLen) {
            maxLen = lenTable[i];
        }        
        if ((head == NULL) && (table[i] != 0)) {
            begin = i+1;
            tail = head = malloc(sizeof(OneStrHash));
            head->hash = table[i];
            head->len = lenTable[i];            
            head->next = NULL;
        }
    }

    for(i=begin;i<arrSize;i++) {
        if (table[i] == 0) {
            continue;
        }
        // 字符串i和已有队列中拼接成的字符串再次拼接，得到新串，放新队列
        newTail = newHead = malloc(sizeof(OneStrHash));
        newHead->hash = table[i];
        newHead->len = lenTable[i];
        newHead->next = NULL;
        tempP = head;
        while(tempP != NULL) {
            if((tempP->hash & table[i]) == 0) {
                newTail->next = malloc(sizeof(OneStrHash));
                newTail = newTail->next;
                newTail->hash = tempP->hash | table[i];
                newTail->len = tempP->len + lenTable[i];
                newTail->next = NULL;
                if (newTail->len > maxLen) {
                    maxLen = newTail->len;
                    if (maxLen >= 26) {
                        return maxLen;
                    }
                }
            }
            tempP = tempP->next;
        }
        // 新队列和已有队列拼接
        tail->next = newHead;
        tail = newTail;
    }

    return maxLen;
}



```