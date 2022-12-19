```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp0(const void *a, const void *b)
{
    return memcmp(*(int **)b, *(int **)a, sizeof(int) * 3);
}

struct MyNode {
    int index;
    int val;
};

int cmp1(const void *a, const void *b)
{
    struct MyNode *na = (struct MyNode *)a;
    struct MyNode *nb = (struct MyNode *)b;
    return na->val - nb->val;
}

int pileBox(int** box, int boxSize, int* boxColSize){
    (void)boxColSize;
    qsort(box, boxSize, sizeof(int *), cmp0);

    struct MyNode *nodes = malloc(sizeof(struct MyNode) * boxSize);
    memset(nodes, 0, sizeof(struct MyNode) * boxSize);

    for (int i = 0; i < boxSize; i++) {
        int find = 0;
        for (int j = i - 1; j >= 0; j--) {
            int index = nodes[j].index;
            if (box[i][0] < box[index][0] && box[i][1] < box[index][1] & box[i][2] < box[index][2]) {
                nodes[i].val = nodes[j].val + box[i][2];
                find = 1;
                break;
            }
        }

        if (find == 0) {
            nodes[i].val = box[i][2];
        }

        nodes[i].index = i;
        qsort(nodes, i + 1, sizeof(struct MyNode), cmp1);

    }

    int res = nodes[boxSize - 1].val;
    free(nodes);
    return res;
}

```
