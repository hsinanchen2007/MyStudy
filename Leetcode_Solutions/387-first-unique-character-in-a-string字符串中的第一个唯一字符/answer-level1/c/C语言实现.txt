### 解题思路
散列表加游标数组实现
C语言代码

### 代码

```c
#define UNSET -1
#define MAX_SIZE 128

typedef struct CurListNode
{
    int index;
    int times;
    int next;
} CurListNode;

typedef CurListNode CurList[MAX_SIZE];

void initial_CurList(CurList list)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        list[i].index = UNSET;
        list[i].times = 0;
        list[i].next = UNSET;
    }
}

int firstUniqChar(char *s)
{
    CurList auxList;
    initial_CurList(auxList);

    int head = UNSET;
    int prePointer = UNSET;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (auxList[(int)s[i]].times == 0)
        {
            auxList[(int)s[i]].index = i;
            if (head == UNSET)
            {
                head = (int)s[i];
                prePointer = (int)s[i];
            }
            else
            {
                auxList[prePointer].next = (int)s[i];
                prePointer = (int)s[i];
            }
        }
        auxList[(int)s[i]].times++;
    }
    if(head == UNSET)
        return -1;
    int searchPointer = head;
    do
    {
        if (auxList[searchPointer].times == 1)
            return auxList[searchPointer].index;
        searchPointer = auxList[searchPointer].next;
    } while (searchPointer != UNSET);
    return -1;
}
```