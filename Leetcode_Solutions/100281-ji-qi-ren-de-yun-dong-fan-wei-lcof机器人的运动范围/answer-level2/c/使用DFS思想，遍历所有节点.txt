### 解题思路
分别遍历所有节点，然后将节点放在链表中，遍历完所有链表后问题解决

### 代码

```c
typedef struct MOVIINGINFO {
    int row;
    int col;
    struct Node node; // 嵌入其中，位置任意
} MOVINGDIRECT;


#define MAX_DIRECT 4

int GetBitVal(int val)
{
    int count;
    count = 0;

    int newRow;
    newRow = val;
    while (newRow != 0) {
        count += (newRow % 10);
        newRow /= 10;
    }

    return count;
}

int CalBitVal(int row, int col)
{
    int count;

    count = 0;
    count += GetBitVal(row);
    count += GetBitVal(col);
    return count;
}
void FreeListNode(struct List *list){

    MOVINGDIRECT *temp = NULL;
    MOVINGDIRECT *release = NULL;
    LIST_FOR_EACH_ENTRY_SAFE(release, temp, list, MOVINGDIRECT, node){
        if (release != NULL)
        {
            free(release);
        }
    }
    return;
}
int GetCount(int m, int n, int k, char *flag)
{
    /* init list */
    struct List *list = NULL;
    list = malloc(sizeof(struct List));
    if (list == NULL) {
        return 0;
    }

    ListInit(list);

    MOVINGDIRECT *firstNode = malloc(sizeof(MOVINGDIRECT));
    if (firstNode == 0) {
        free(list);
        return 0;
    }
    memset(firstNode, 0x0, sizeof(MOVINGDIRECT));
    ListAddTail(list, &firstNode->node);
    flag[firstNode->row * n + firstNode->col] = 1;

    int count;
    count = 0;
    while (!ListEmpty(list)) {
        MOVINGDIRECT *nodeInfo = NULL;

        nodeInfo = LIST_HEAD_ENTRY(list, MOVINGDIRECT, node);
        if (nodeInfo == NULL) {
            break;
        }

        ListRemove(&nodeInfo->node);
        count++;
        int direct[MAX_DIRECT][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

        for (int index = 0; index < MAX_DIRECT; index++) {
            int newRow;
            int newCol;
            newRow = nodeInfo->row + direct[index][0];
            newCol = nodeInfo->col + direct[index][1];
            if ((newRow < 0) || (newRow >= m)) {
                continue;
            }

            if ((newCol < 0) || (newCol >= n)) {
                continue;
            }

            if (flag[newRow * n + newCol] != 0) {
                continue;
            }

            int bit;
            bit = CalBitVal(newRow, newCol);
            if (bit > k) {
                continue;
            }

            MOVINGDIRECT *newNode = malloc(sizeof(MOVINGDIRECT));
            if (newNode == 0) {
                FreeListNode(list);
                free(list);
                return 0;
            }

            memset(newNode, 0x0, sizeof(MOVINGDIRECT));
            newNode->col = newCol;
            newNode->row = newRow;
            ListAddTail(list, &newNode->node);
            flag[newNode->row * n + newNode->col] = 1;
        }
        free(nodeInfo);
        nodeInfo = NULL;
    }

    FreeListNode(list);
    free(list);
    return count;
}

int movingCount(int m, int n, int k)
{
    char *flag = NULL;

    if ((m == 0) && (n == 0)) {
        return 0;
    }

    flag = malloc((m * n + 1) * sizeof(char));
    if (flag == NULL) {
        return 0;
    }
    memset(flag, 0x0, (m * n + 1) * sizeof(char));

    int count = GetCount(m, n, k, flag);
    free(flag);
    flag = NULL;
    return count;
}


```