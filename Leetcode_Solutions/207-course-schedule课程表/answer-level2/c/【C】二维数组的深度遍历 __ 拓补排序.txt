1. 由于对图不熟，就想着用二维数组的遍历来搞定，结果时间复杂度有点慢。
   (1) 用一个数组flag记录每一次自上而下的路径。
   (2) 用数组flagg记录当前边，是否已经验证过了，如果是，则忽略，加快一下速度。
![image.png](https://pic.leetcode-cn.com/c3b00ae9c7dd3b7372b5abf3fb6bdc23830efd0559d5d9abb381dd01c48292da-image.png)

2. 学习了一下拓补排序，代码实现了一下，速度果然挺快的。
![image.png](https://pic.leetcode-cn.com/314e1a1668e4cc39723c2da4523011e6eafa534b13a8c6c76236ea96a9092c2a-image.png)

3. 自己琢磨的路子还是没有前辈们沉淀的厉害，看来还是需要多学习。

采用二维数组的深度遍历：
```
#define printf
bool DepthSearch(int **prerequisites, int prerequisitesSize, int id, int *flag, int *flagg)
{
    bool ret = true;

    flag[id] = 1;
    
    for (int j = 0; j < prerequisitesSize; j++) {
        if (flagg[j] == 1) {
            continue;
        }
        if (prerequisites[j][0] == prerequisites[id][1]) {
            if (flag[j] == 1) {
                return false;
            }
            ret = DepthSearch(prerequisites, prerequisitesSize, j, flag, flagg);
            if (ret == false) {
                return false;
            }
        }
    }
    if (ret == true) {
        printf("id: %d\r\n", id);
        flag[id] = 0;
        flagg[id] = 1;
    }
    return ret;
}


bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    bool ret = true;
    
    int *flag = (int *)malloc(prerequisitesSize * sizeof(int));
    if (flag == NULL) {
        return false;
    }
    memset(flag, 0, prerequisitesSize * sizeof(int));

    int *flagg = (int *)malloc(prerequisitesSize * sizeof(int));
    if (flagg == NULL) {
        return false;
    }
    memset(flagg, 0, prerequisitesSize * sizeof(int));    
    
    for (int i = 0; i < prerequisitesSize; i++) {
        if (flagg[i] == 1) {
            continue;
        }
        ret = DepthSearch(prerequisites, prerequisitesSize, i, flag, flagg);
        if (ret == false) {
            break;
        }
    }
    free(flag);
    free(flagg);
    return ret;
}
```


采用拓补排序：
```
typedef struct NODE{
    int id;
    struct NODE *next;
}LINK_NODE;

typedef struct {
    int key;
    int in;
    LINK_NODE *head;
}LINK_ELEMENT;

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    if (prerequisites == NULL || prerequisitesSize == 0) {
        return true;
    }
    int stack[1000] = {0};
    int top = 0;
    
    LINK_ELEMENT *graph = (LINK_ELEMENT *)malloc(numCourses * sizeof(LINK_ELEMENT));
    if (graph == NULL) {
        return false;
    }
    memset(graph, 0, numCourses * sizeof(LINK_ELEMENT));

    int tt = numCourses > prerequisitesSize ? numCourses : prerequisitesSize;
    for (int i = 0; i < tt; i++) {
        if (i < numCourses) {
            graph[i].key = i;
        }

        if (i < prerequisitesSize) {
            LINK_NODE *tmp = (LINK_NODE *)malloc(sizeof(LINK_NODE));
            if (tmp == NULL) {
                return false;
            }
            tmp->id = prerequisites[i][1];
            tmp->next = NULL;
            if (graph[prerequisites[i][0]].head != NULL) {
                tmp->next = graph[prerequisites[i][0]].head;
            }
            graph[prerequisites[i][0]].head = tmp;    
            (graph[prerequisites[i][1]].in)++;
        }
    }
    
    for (int i = 0; i < numCourses; i++) {
        if (graph[i].in == 0) {
            stack[top++] = i;
        }
    }

    int count = 0;
    while (top != 0) {
        int tmp = stack[--top];
        count++;
        LINK_NODE *head = graph[tmp].head;
        while (head != NULL) {
            (graph[head->id].in)--;
            if (graph[head->id].in == 0) {
                stack[top++] = head->id;
            }
            head = head->next;
        }
    }
    return count == numCourses;
}
```

