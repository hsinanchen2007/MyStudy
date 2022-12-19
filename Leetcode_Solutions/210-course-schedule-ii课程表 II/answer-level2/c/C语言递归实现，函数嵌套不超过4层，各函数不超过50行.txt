这个问题可以这样想：
1、当我要学习一门课（如A课程，作为入参）的时候，若已学则不再学，若还没有学则看下有没有依赖的课，没有的话直接学完，标记已学，输出当前课程。
2、若我要学的课程有依赖的（如依赖课程A），那么将当前的课程（设课程B）排在计划中，先学依赖的课程A，将课程A作为入参重复步骤1即可。学完A即可接着学课程B
3、遍历所有课程，重复实行1、2
4、如果发现依赖的课程已经在计划中，说明依赖成环，则不可能有排序结果，返回空数组。


既然使用递归那么需要明确递归退出条件，当满足如下条件时要退出

1、当前要学的课程不依赖于任何课程（返回true，输出当前课程）
2、当前课程已经学过了（返回true）
3、当前课程排在计划中（返回false，依赖成环）

参考代码：

```

/* *
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 已学习标记 */
#define STUDYED_FLAG 0x10
/* 计划中标记 */
#define PLANED_FLAG 0x20

// 申请输出内存
int *mallocRetArrSpace(int numCourses)
{
    int *retArr = NULL;
    if (numCourses == 0) {
        return NULL;
    }
    retArr = (int *)malloc(numCourses * sizeof(int));
    /* 预留：处理申请失败情况 */
    (void)memset((void *)retArr, 0, numCourses * sizeof(int));
    return retArr;
}

// 申请表格，用于存放课程依赖关系表
char **mallocTableSpace(int num)
{
    int i;
    char **table = NULL;
    if (num == 0) {
        return NULL;
    }
    table = (char **)malloc(num * sizeof(char *));
    /* 预留：处理申请失败情况 */
    for (i = 0; i < num; i++) {
        table[i] = (char *)malloc(num * sizeof(char));
        /* 预留：处理申请失败情况 */
        (void)memset((void *)table[i], 0, num * sizeof(char));
    }
    return table;
}

// 释放关系表空间
void freeTableSpace(char **table, int tblSize)
{
    int i;

    for (i = 0; i < tblSize; i++) {
        free(table[i]);
    }
    free(table);
}

// 获取依赖课程
bool getNeedCoures(char **table, int tblSize, int curCourse, int *retArr, int *pOutIndex)
{
    int x;
    // 课程已学过
    if (table[curCourse][curCourse] & STUDYED_FLAG) {
        return true;
    }
    // 课程已计划中，依赖成环
    if (table[curCourse][curCourse] & PLANED_FLAG) {
        return false;
    }
    // 查找当前课程依赖的课程
    for (x = 0; x < tblSize; x++) {
        // 有依赖的课，当前课程加入计划中
        if (table[curCourse][x] & 1) {
            table[curCourse][curCourse] |= PLANED_FLAG;
            if (getNeedCoures(table, tblSize, x, retArr, pOutIndex) == false) {
                return false;
            }
            // 已学完依赖的课程，当前课程继续学，移出计划中
            table[curCourse][curCourse] &= ~PLANED_FLAG;
        }
    }
    // 当前的课程已无依赖，直接学完
    table[curCourse][curCourse] |= STUDYED_FLAG;
    // 输出当前课程到输出列表
    retArr[*pOutIndex] = curCourse;
    (*pOutIndex)++;
    return true;
}

int *findOrder(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize, int *returnSize)
{
    int *retArr = NULL;
    int outIndex = 0;
    char **table = NULL;
    int i, x, y;

    // 入参有效性判断
    if ((prerequisites == NULL) || (prerequisitesColSize == NULL) || (returnSize == NULL)) {
        return NULL;
    }

    retArr = mallocRetArrSpace(numCourses);
    /* 预留：处理申请失败情况 */
    table = mallocTableSpace(numCourses);
    /* 预留：处理申请失败情况 */
    /* 构建课程依赖关系表 */
    for (i = 0; i < prerequisitesSize; i++) {
        y = prerequisites[i][0];
        x = prerequisites[i][1];
        table[y][x] |= 1;
    }
    // 遍历所有课程
    for (y = 0; y < numCourses; y++) {
        // 若已学，查看下一个
        if (table[y][y] & STUDYED_FLAG) {
            continue;
        }

        // 获取依赖课程
        if (getNeedCoures(table, numCourses, y, retArr, &outIndex) == false) {
            // 获取失败，成环情况
            outIndex = 0;
            break;
        }
    }

    // 释放关系表
    freeTableSpace(table, numCourses);
    // 输出
    *returnSize = outIndex;
    return retArr;
}
```






![image.png](https://pic.leetcode-cn.com/e43e515df138cc2f6da0534ec2fb6e79582be933c7ce663c8b2f22099f2bfec5-image.png)


