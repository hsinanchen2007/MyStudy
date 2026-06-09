执行结果：通过
显示详情
执行用时 :64 ms,在所有 C 提交中击败了78.43% 的用户
内存消耗 :10.6 MB, 在所有 C 提交中击败了100.00%的用户

思想：你只需要关系身高比你高的人，比你矮的人忽略，你在比你高的人里相对位置不变即可，绝对位置可能改变。
基于这给思想，先排序，把身高高的排在前面，如果身高相同，则将k值小的排前面，然后遍历这个队列，插入排序，每个元素的插入位置就是当前阶段的k值。

```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int Cmp(const void *a, const void *b)
{
    if ((*(int **)a)[0] != (*(int **)b)[0]) {
        return (*(int **)b)[0] - (*(int **)a)[0]; // 不同身高按h降序
    } else {
        return (*(int **)a)[1] - (*(int **)b)[1]; // 相同身高按k升序
    }
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    if (people == NULL) return NULL;
    int **ret = (int **)malloc(peopleSize * sizeof(int *));
    for (int i = 0; i < peopleSize; i++) {
        ret[i] = (int *)malloc(2 * sizeof(int));
    }
    *returnColumnSizes = (int *)malloc(peopleSize * sizeof(int));
    
    // 排序
    qsort(people, peopleSize, sizeof(people[0]), Cmp);
    for (int i = 0; i < peopleSize; i++) {
        for (int j = i; j > people[i][1]; j--) {
            ret[j][0] = ret[j - 1][0];
            ret[j][1] = ret[j - 1][1];
        }
        ret[people[i][1]][0] = people[i][0];
        ret[people[i][1]][1] = people[i][1];
    }
    
    *returnSize = peopleSize;
    for (int i = 0; i < peopleSize; i++) {
        (*returnColumnSizes)[i] = peopleColSize[i];
    }
    return ret;
}
```
