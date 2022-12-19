/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void CntDegree(int* degree, int size, int** courses, int arc)
{
    for (int i = 0; i < size; i++) {
        degree[i] = 0;
    }

    for (int i = 0; i < arc; i++) {
        degree[courses[i][1]]++;
    }    

    return;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int degree[numCourses];
    int leaf[numCourses];
    int leafnode = 0;

    CntDegree(degree, numCourses,prerequisites, prerequisitesSize);

    while (true) {
        int leafNum = leafnode;

        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                leaf[leafnode++] = i;
                degree[i]--;
                printf("leaf %d\n",leaf[leafnode - 1]);
            }
        }

        if (leafnode == leafNum) {
            break;
        }

        for (int i = leafNum; i < leafnode; i++) {
            for (int j = 0; j < prerequisitesSize; j++) {
                if (prerequisites[j][0] == leaf[i]) {
                    degree[prerequisites[j][1]]--;
                    printf("degress index %d degree %d\n",prerequisites[j][1],degree[prerequisites[j][1]]);
                }
            }            
        }
    }

    if (leafnode != numCourses) {
        *returnSize = 0;
        return NULL;
    }

    int* ans = (int*)malloc(sizeof(int) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        ans[i] = leaf[--leafnode];
        printf("ans %d\n",leaf[leafnode]);
    }

    *returnSize = numCourses;
    return ans;
}