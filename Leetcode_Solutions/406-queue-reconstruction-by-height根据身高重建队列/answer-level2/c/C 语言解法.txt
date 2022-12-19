### 解题思路

### 代码

```C
int comp(void *a, void *b) {
    int *x = *(int **)a;
    int *y = *(int **)b;
    if (x[0] < y[0]) {
        return 1;
    }
    if (x[0] > y[0]) {
        return -1;
    }
    if (x[1] < y[1]) {
        return -1;
    }
    if (x[1] > y[1]) {
        return 1;
    }
    return 0;
}

struct ListNodeFW {
    int val[2];
    struct ListNodeFW *next;
};

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    if (peopleSize == 0) {
        *returnSize = 0;
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }
    qsort(people, peopleSize, sizeof(int) * 2, comp);

    struct ListNodeFW *head = (struct ListNodeFW *)malloc(sizeof(struct ListNodeFW));
    struct ListNodeFW *pre = head;
    pre->next = (struct ListNodeFW *)malloc(sizeof(struct ListNodeFW));
    pre->next->next = NULL;
    pre->next->val[0] = people[0][0];
    pre->next->val[1] = people[0][1];
    pre = pre->next;
    for(int i = 1; i < peopleSize; i++) {
        if (pre->val[0] == people[i][0]) {
            pre->next = (struct ListNodeFW *)malloc(sizeof(struct ListNodeFW));
            pre->next->next = NULL;
            pre->next->val[0] = people[i][0];
            pre->next->val[1] = people[i][1];
            pre = pre->next;
        } else {
            int pos = people[i][1];
            struct ListNodeFW *temp = head;
            while(pos > 0 && temp != NULL) {
                pos--;
                temp = temp->next;
            }
            if (temp == NULL) {
                pre->next = (struct ListNodeFW *)malloc(sizeof(struct ListNodeFW));
                pre->next->next = NULL;
                pre->next->val[0] = people[i][0];
                pre->next->val[1] = people[i][1];
                pre = pre->next;
            } else {
                struct ListNodeFW *V = (struct ListNodeFW *)malloc(sizeof(struct ListNodeFW));
                V->val[0] = people[i][0];
                V->val[1] = people[i][1];
                V->next = temp->next;
                temp->next = V;
                if (pre == temp) {
                    pre = pre->next;
                }
            }
        }
    }
    pre->next = NULL;

    *returnSize = peopleSize;
    int **res = (int **)malloc(sizeof(int *) * peopleSize);
    head = head->next;
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * peopleSize);
    int i = 0;
    while(head != NULL) {
        res[i] = (int *)malloc(sizeof(int) * 2);
        res[i][0] = head->val[0];
        res[i][1] = head->val[1];
        (*returnColumnSizes)[i] = 2;
        struct ListNodeFW *pre = head;
        head = head->next;
        free(pre);
        i++;
    }
    return res;
}
```