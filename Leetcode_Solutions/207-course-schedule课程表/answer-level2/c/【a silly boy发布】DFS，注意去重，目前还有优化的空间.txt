![D7D584FF-6EA0-42AB-AA9B-31C841D9DAD8.jpeg](https://pic.leetcode-cn.com/3dac3bc4f5e6c4cac8ae3e34087a8f75c2a36e2d92a47cb4202481ccc407dada-D7D584FF-6EA0-42AB-AA9B-31C841D9DAD8.jpeg)

```
int cmp(const void *a, const void *b)
{
    int *tmpA = *(int **)a;
    int *tmpB = *(int **)b;

    return tmpA[1] - tmpB[1];
}

bool SubFuncDfs(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int *numCourseFlag, int *numCourseFlagCpy, int index)
{
    int i;
    bool returnValue = true;
    //printf("numCourseFlag[%u]: %u\n", index, numCourseFlag[index]);
    numCourseFlagCpy[index] = 1;
    if (numCourseFlag[index] == 1) {
        return false;
    }
    numCourseFlag[index] = 1;


    for (i = 0; i < prerequisitesSize; i++) {
        if (prerequisites[i][1] == index) {
           returnValue = SubFuncDfs(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize, numCourseFlag, numCourseFlagCpy, prerequisites[i][0]);

           if (returnValue == false) {
               return false;
           }
           numCourseFlag[prerequisites[i][0]] = 0;
        }
    }

    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int i = 0;
    int *numCourseFlag = (int *)malloc(numCourses * sizeof(int));
    memset(numCourseFlag, 0, numCourses * sizeof(int));

    int *numCourseFlagCpy = (int *)malloc(numCourses * sizeof(int));
    memset(numCourseFlagCpy, 0, numCourses * sizeof(int));

    if (prerequisitesSize == 1) {
        return true;
    }
    //qsort(prerequisites, prerequisitesSize, sizeof(prerequisites[0]), cmp);
    bool returnValue = false;
    for (i = 0; i < numCourses; i++) {
        //printf("i: %u\n", i);
        if (numCourseFlagCpy[i] == 0) {
            memset(numCourseFlag, 0, numCourses * sizeof(int));
            returnValue = SubFuncDfs(numCourses, prerequisites, prerequisitesSize,prerequisitesColSize, numCourseFlag, numCourseFlagCpy, i);
            if (returnValue == false) {
                return false;
            }
        }
    }

    return true;
}
```
