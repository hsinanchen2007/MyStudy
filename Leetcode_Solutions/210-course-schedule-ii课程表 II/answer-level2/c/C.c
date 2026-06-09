![image.png](https://pic.leetcode-cn.com/9e5ff189690d2943a083fade6a278c7fff5302374a6dd6b82089f37da9bb2528-image.png)

```
#define MAX 3000

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int *ret;
    int temp[MAX];
    int count = 0;
    int flag;

    ret = (int *)malloc(MAX * sizeof(int));
    memset(temp, 0, MAX * sizeof(int));

    //计算每个数的入度
    for (int i = 0; i < prerequisitesSize; i++) {
        temp[prerequisites[i][0]]++;
    }

    //输出入度为0的节点，即完全不依赖其他的节点
    for (int i = 0; i < numCourses; i++) {
        if (temp[i] == 0) {
            ret[count++] = i;
        }
    }

    while (count < numCourses) {
        flag = 0;
        for (int i = 0; i < prerequisitesSize; i++) {
            //规则：基于右值（依赖项）降度，左值（被依赖项）不降度
            if (prerequisites[i][0] != -1 && temp[prerequisites[i][0]] > 0 && 
            temp[prerequisites[i][1]] == 0) {
                temp[prerequisites[i][0]]--;
                if (temp[prerequisites[i][0]] == 0) {
                    ret[count++] = prerequisites[i][0];
                    flag = 1;
                }
                prerequisites[i][0] = -1; //被依赖项不能参与降度
            }
        }
        if (flag == 0) {
            break;
        }
    }

    if (count != numCourses) {
        *returnSize = 0;
    } else {
        *returnSize = numCourses;
    }

    return ret;
}
```