![image.png](https://pic.leetcode-cn.com/de4ca613608b063a3ca7d495b3d389794e316eb6de552add922f6a28cf33806c-image.png)

### 解题思路
统计每个砖块边缘的hash值

### 代码

```c
struct hashInfo {
    int key;
    int val;
};

struct hashNode {
    struct hashInfo hash;
    struct hashNode *next;
};

struct hashMap {
    struct hashNode *hashN;
    int size;
};

struct hashMap g_hashMap;

void CreatHash(int size)
{
    if (size <= 0) {
        return;
    }

    g_hashMap.hashN = (struct hashNode *)malloc(size * sizeof(struct hashNode));
    g_hashMap.size = size;
    memset(g_hashMap.hashN, 0, size * sizeof(struct hashInfo));
    
    return;
}

void PutHash(int key)
{
    int pos = abs(key) % g_hashMap.size;
    struct hashNode *temp = &g_hashMap.hashN[pos];
    struct hashNode *newNode;

    if (temp->hash.key == 0) {
        temp->hash.key = key;
        temp->hash.val = 1;
        return;
    }

    while (temp) {
        if (temp->hash.key == key) {
            temp->hash.val++;
            return;
        } else {
            if (temp->next == NULL) {   //为后续添加节点作准备
                break;
            }
            temp = temp->next;
        }
    }

    newNode = (struct hashNode *)malloc(sizeof(struct hashNode));
    newNode->hash.key = key;
    newNode->hash.val = 1;
    newNode->next = NULL;
    temp->next = newNode;

    return;
}

int GetMaxValue()
{
    int size = g_hashMap.size;
    int max = 0;
    struct hashNode *temp;

    for (int i = 0; i < size; i++) {
        temp = &g_hashMap.hashN[i];
        while (temp) {
            if (max < temp->hash.val) {
                max = temp->hash.val;
                printf("%d  %d\n", temp->hash.key, max);
            }
            temp = temp->next;
        }
    }

    return max;
}

int leastBricks(int** wall, int wallSize, int* wallColSize){
    int temp;

    CreatHash(1024); //初始化hash桶大小
    for (int i = 0; i < wallSize; i++) { //分别统计每行的累计hash
        temp = 0;
        for (int j = 0; j < wallColSize[i] - 1; j++) {
            temp += wall[i][j];            
            PutHash(temp);
        }
    }

    return (wallSize - GetMaxValue());
}
```