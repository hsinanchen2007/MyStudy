
# 方法1：使用点的入度实现，全部用例跑过。如下代码所示：

```
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int a[3000] = {0};
    int i,j, t;
    for (i = 0; i < numCourses; i++) {
        a[i] = 0;
    }
    //记录所有点的入度
    for (i = 0; i < prerequisitesSize; i++) {
        a[prerequisites[i][0]]++;   
    }
    
    //返回的数组
    int * b = (int *)malloc(sizeof(int) * numCourses);
    int top = 0;
    //入度为0的点放入返回数组中
    for (i = 0; i < numCourses; i++) {
        if(0 == a[i]) {
            b[top++] = i;
        }
    }

    //处理入度不为0的点
    for (i= 0; i< numCourses; i++) {
        t = 0;
        for (j = 0; j < prerequisitesSize; j++) {
            if (prerequisites[j][0] != -1 &&
                a[prerequisites[j][0]] > 0 && 
                a[prerequisites[j][1]] == 0) {
                    a[prerequisites[j][0]]--;
                    if (0 == a[prerequisites[j][0]]) {
                        b[top++] = prerequisites[j][0];
                    }
                    prerequisites[j][0] = -1;
                }
                t = 1;
        }
        if (t == 0) {
            break;
        }
    }
    if (numCourses != top) {
        *returnSize = 0;
    } else {
        *returnSize = numCourses;
    }
    return b;
}
```
# 方法2：使用邻接表实现，部分用例跑过。当数组的大小超过100的时候，栈溢出。

```
typedef struct NODE
{   
    int key;
    struct NODE * next;
}NODE_STR;


typedef struct TUO_PU {
    int in;
    struct NODE * head;
}TUO_PU_STRU;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){

    //建立拓扑结构
    TUO_PU_STRU * tuopus = (TUO_PU_STRU *)malloc(sizeof(TUO_PU_STRU) * numCourses);
    int *ret = (int *)malloc(sizeof(int) * numCourses);
    int i,start, end;
    int count = 0;
    int zhan[1000];
    int top = -1;
    int index = 0;
    
    NODE_STR * p;
    for (i= 0; i < numCourses; i++) {
        tuopus[i].in = 0;
        tuopus[i].head = NULL;
    }

    for (i = 0; i < prerequisitesSize; i++)
    {
        start = prerequisites[i][1];
        end = prerequisites[i][0];
        tuopus[end].in++;
        p = (NODE_STR*)malloc(sizeof(NODE_STR));
        p->key = end;
        p->next = NULL;
        if (NULL == tuopus[start].head)
        {
            tuopus[start].head = p;
        } else {
            p->next = tuopus[i].head;
            tuopus[start].head = p;
        }
    }

    
    // 通过栈的方式判断是否有循环图在里面 入栈
    for (i = 0; i < numCourses; i++) {
        if (0 == tuopus[i].in) {
            zhan[++top] = i;
            count++;
        }
    }

    //通过出栈的方式确定是否有循环图
    while (-1 != top)
    {
        i = zhan[top--];
        ret[index++] = i;
       
        while (NULL != tuopus[i].head)
        {
            p = tuopus[i].head;
            tuopus[p->key].in--;
            if (0 == tuopus[p->key].in) {
                zhan[++top] = p->key;
                count++;
            }
            tuopus[i].head = p->next;
        }
    }
    if (count < numCourses) {
        *returnSize = 0;
    } else {
        *returnSize = numCourses;
    }
    for (i = 0; i < numCourses; i++)
    {
        while (tuopus[i].head)
        {
            p = tuopus[i].head;
            tuopus[i].head = p->next;
            free(p);
        }
    }
    
    return ret;
}
```
