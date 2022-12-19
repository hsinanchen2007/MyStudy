![image.png](https://pic.leetcode-cn.com/793def46ba0ae3fda69e9fb481ce9011a09cbf59f5f9ad1a244df30f65080c71-image.png)
1、对二维数组进行排序，用qsort。
2、写一个优先级链表，头部是最大值。核心代码如下，当第i门课的课时 + 前（i-1）门课的最优值超过第i门课的截止时间endDay时，删除链表的头部元素（最大值）。
```
for (int i = 0; i < coursesSize; i++) {
        courseLen = courses[i][0];
        endDay = courses[i][1];
        tempEndDay = courseLen + priLL->priTotal;
        if (tempEndDay <= endDay) {
            PriLinkedListAdd(priLL, courseLen);
        } else {
            PriLinkedListAdd(priLL, courseLen);
            PriLinkedListDelHead(priLL);
        }
    }
```

==============================================================
```
int cmp(const void* a, const void* b)
{
    int* ptrA = *(int** )a;
    int* ptrB = *(int** )b;

    if (ptrA[1] == ptrB[1]) {
        return (ptrA[0] - ptrB[0]);
    }
    return (ptrA[1] - ptrB[1]);
}

typedef struct {
    int value;
    struct MyNode* next;
}MyNode;

typedef struct {
    MyNode* head;
    int priLength;
    int priTotal;
} PriLinkedList;

PriLinkedList* PriLinkedListCreate() {
    PriLinkedList* priLL = (PriLinkedList* )malloc(sizeof(PriLinkedList));
    priLL->head = NULL;
    priLL->priLength = 0;
    priLL->priTotal = 0;
    return priLL;
}

void PriLinkedListAdd(PriLinkedList* obj, int val) {
    MyNode* ptrNode = obj->head;
    MyNode* prevNode = NULL;
    MyNode* newNode = (MyNode* )malloc(sizeof(MyNode));
    newNode->value = val;
    while (ptrNode) {
        if (ptrNode->value > val) {
            prevNode = ptrNode;
            ptrNode = ptrNode->next;
        } else {
            break;
        }
    }
    if (!obj->head || (ptrNode == obj->head)) {
        newNode->next = obj->head;
        obj->head = newNode;
    } else {
        prevNode->next = newNode;
        newNode->next = ptrNode;
    }
    obj->priLength += 1;
    obj->priTotal += val;
}

void PriLinkedListDelHead(PriLinkedList* obj)
{
    MyNode* oldHead = obj->head;
    obj->head = oldHead->next;
    obj->priLength -= 1;
    obj->priTotal -= oldHead->value;
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize)
{
    int courseLen, endDay, tempEndDay;
    qsort(courses, coursesSize, sizeof(courses[0]), cmp);

    PriLinkedList* priLL = PriLinkedListCreate();
    for (int i = 0; i < coursesSize; i++) {
        courseLen = courses[i][0];
        endDay = courses[i][1];
        tempEndDay = courseLen + priLL->priTotal;
        if (tempEndDay <= endDay) {
            PriLinkedListAdd(priLL, courseLen);
        } else {
            PriLinkedListAdd(priLL, courseLen);
            PriLinkedListDelHead(priLL);
        }
    }
    return priLL->priLength;
}
```

