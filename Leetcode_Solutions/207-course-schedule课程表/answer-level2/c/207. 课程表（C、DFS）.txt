### 解题思路
整体思路：
对于其中一门课程i，去找依赖的课程i1，再找依赖的依赖的课程i2，....,直到找不到依赖，则该课程可选。如果存在循环依赖，则不可选。如果被依赖的课程已经确认可选，则不必继续检查，肯定可选。

本轮待定列表：如果当前课程依赖于待定列表中的课程，则不可能完成。如果最终能完成，则可存入已选列表。 但没必要全部加入，只加入第一个课程即可。
已选列表：当前课程可以依赖于已选列表。没有循环依赖的待定列表，没有依赖的课程，都可以加入。


使用MAP保存本轮已查看过的课程，如果下一个依赖的课程ik在本轮查看过的课程里面，则是循环依赖。则课程i不可选。
遍历到1个依赖的课程时，如果该课程已经确认可选，则不需要继续往后遍历了，当前课程肯定可选。为了方便查看哪些课程确认可选，用另一个MAP保存已经确认可选的课程。


### 执行结果
执行结果：通过 
执行用时 :24 ms, 在所有 C 提交中击败了95.97%的用户
内存消耗 :7.9 MB, 在所有 C 提交中击败了100.00%的用户

### 代码
```c
typedef struct PRENODE_S {
    int pre;
    struct PRENODE_S *next;
}PRENODE_S;

PRENODE_S **g_preMap = NULL;
void InitPreMap(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize)
{
    int i;
    int cur;
    int index;

    g_preMap = (PRENODE_S **)malloc(sizeof(PRENODE_S *) * numCourses);
    if (g_preMap == NULL) {
        return;
    }
    memset(g_preMap, 0, sizeof(PRENODE_S *) * numCourses);

    for (i = 0; i < prerequisitesSize; i++) {
        cur = prerequisites[i][0];
        PRENODE_S *preNode = (PRENODE_S *)malloc(sizeof(PRENODE_S));
        if (preNode == NULL) {
            continue;
        }
        preNode->pre = i;
        preNode->next = NULL;

        PRENODE_S *tmpNod = g_preMap[cur];
        if (tmpNod != NULL) {
            preNode->next = tmpNod;
        }
         g_preMap[cur] = preNode;
    }

    return;
}

void FreePreMap(int numCourses)
{
    int i;
    for (i = 0; i < numCourses; i++) {
        PRENODE_S *node = g_preMap[i];
        while (node != NULL) {
            PRENODE_S *tmpNode = node;
            node = node->next;
            free(tmpNode);
        }
    }

    return;
}


bool IsIn(int *courses, int numCourses, int cur) 
{
    if (cur < numCourses) {
        return courses[cur] == 1 ? true : false;
    }

    return false;
}

void PutIn(int *courses, int numCourses, int cur) 
{
    if (cur < numCourses) {
        if (cur)
        courses[cur] = 1;
    }

    return;
}


bool dfs(int cur, int *candidate, int *selected, int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    /* 遍历candidate， */
    int j;
    int curCourse, preCourse;

    curCourse = prerequisites[cur][0];
    if (IsIn(selected, numCourses, curCourse)) {
        return true;
    }

    for (j = 1; j < prerequisitesColSize[cur]; j++) {
        preCourse = prerequisites[cur][j];
        if (IsIn(selected, numCourses, preCourse)) {
            continue;
        } else if (g_preMap[preCourse] == NULL) {
            PutIn(selected, numCourses, preCourse);
            continue;
        } else if (IsIn(candidate, numCourses, preCourse)) {
            return false;
        } else {
            PutIn(candidate, numCourses, preCourse);

            PRENODE_S *preCourses = g_preMap[preCourse];
            PRENODE_S *pre;
            for (pre = preCourses; pre != NULL; pre = pre->next) {
                //printf("%d %d\n", preCourse, pre->pre);
                bool ret = dfs(pre->pre, candidate, selected, numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);
                if (ret == false) {
                    return false;
                } 
            }
            PutIn(selected, numCourses, preCourse);
        }
    }

    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    if (prerequisites == NULL || prerequisitesColSize == NULL) {
        return false;
    }

    if (numCourses == 0) {
        return false;
    }
    
    /* 已选列表：当前课程可以依赖于已选列表。没有循环依赖的课程，加入已选列表。 */
    int *selected = (int *)malloc(sizeof(int) * numCourses);
    if (selected == NULL) return false;
    memset(selected, 0, sizeof(int) * numCourses);
    
    /* 本轮待定列表：如果当前课程依赖于待定列表中的课程，则不可能完成。如果最终能完成，则转入已选列表。 */
    int *cadidate = (int *)malloc(sizeof(int) * numCourses);
    if (cadidate == NULL) {
        free(selected);
        return false;
    }
    memset(cadidate, 0, sizeof(int) * numCourses);

    InitPreMap(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);

    int i;
    bool ret;
    for (i = 0; i < prerequisitesSize; i++) {
        ret = dfs(i, cadidate, selected, numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);
        if (ret == false) {
            break;
        }
    }

    if (selected != NULL) {
        free(selected);
    }
    
    if (cadidate != NULL) {
        free(cadidate);
    }
    
    FreePreMap(numCourses);

    return ret;
}
```