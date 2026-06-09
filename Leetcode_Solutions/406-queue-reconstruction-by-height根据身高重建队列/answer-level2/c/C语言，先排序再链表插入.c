### 解题思路
此处撰写解题思路
1、先排序（身高相等则比较K，否则直接比身高，从高到矮）；
2、借助链表插入（效率高一些）
3、输出处理

### 代码

```c


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define PEOPLE_LEN 2

typedef struct node
{
	int high;
    int pos;
	struct node *next;
} Linklist;

/* 创建链表，带头结点 */
Linklist *create()
{
	Linklist *head;
	head = (Linklist *)malloc(sizeof(Linklist));
	head->next=NULL;
	return head;	
}
/* 销毁链表 */
void destroy(Linklist *head)
{
    Linklist *p, *q;
    p = head;
	while (p) {
        q = p->next;
        free(p);
        p = q;
    }
}

Linklist *fine_node(Linklist *head, Linklist *node) {
    Linklist *p = head->next;
    int temp = 0;

    while(p) {
        if (p->high >= node->high) {
            temp++;
            if (temp == node->pos) {
                return p;
            }
        }

        p = p->next;
    }

    return head;
}

//插入的元素排在后面
Linklist *node_insert(Linklist *head, Linklist *node) 
{
	Linklist *t;
	t = fine_node(head, node);
	node->next = t->next;
	t->next = node;
	return head;
}

int cmp(int *ap, int *bp) {
    int *a = *(int**)ap;
    int *b = *(int**)bp;
    if (a[0] == b[0]) {
        return a[1] - b[1];
    } else {
        return b[0] - a[0];
    }
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int i;
    int** res;
    Linklist *head = create();
    Linklist *node;

    if (people == NULL || peopleSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    /* 排序 */
    qsort(people, peopleSize, sizeof(int*), cmp);
    /* 按pos序号插入 */
    for (i = 0; i < peopleSize; i++) {
        node = (Linklist *)malloc(sizeof(Linklist));
        node->high = people[i][0];
        node->pos = people[i][1];
        node->next = NULL;
        head = node_insert(head, node);
    }

    /* 输出 */
    i = 0;
    node = head->next;
    res = (int **)malloc(sizeof(int *) * peopleSize);
    while (node) {
        res[i] = (int *)malloc(sizeof(int) * PEOPLE_LEN);
        res[i][0] = node->high;
        res[i][1] = node->pos;
        i++;
        node = node->next;
    }

    destroy(head);

    *returnSize = peopleSize;
    *returnColumnSizes = peopleColSize;

    return res;
}
```