
难点在于搞懂C版本的参数问题 ^_^
 * 排序，都按升序排
 * 贪心算法：本题目的特点是无后效性，先排最小的，再排次小的。
 * 插入法，找到元素对应的位置，people[i][1]就是元素people[i]所在的位置 = 其前面的空位数量 + people[i][0]的数量

```
int compare(const void *a, const void *b)
{
    const int *pa = *(const int **)a;
    const int *pb = *(const int **)b;
    return pa[0] == pb[0] ? pa[1] - pb[1] :pa[0] - pb[0];
}
```

```
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int ** resort_people;
    int pos;

    //TODO: 处理malloc失败
    resort_people = (int **)malloc(peopleSize * sizeof(int *));
    for(int i = 0; i < peopleSize; i++) {
        int size = sizeof(int) * peopleColSize[i];
        resort_people[i] = (int *)malloc(size);
        memset(resort_people[i], -1, size);
    }

    qsort(people, peopleSize, sizeof(int *), compare);
    for (int i = 0; i < peopleSize; i++) {
        pos = people[i][1] + 1;
        for (int j = 0; j < peopleSize; j++) {
            if ((resort_people[j][0] == -1 || resort_people[j][0] == people[i][0]) && (--pos == 0)) {
                    resort_people[j][0] = people[i][0];
                    resort_people[j][1] = people[i][1];
                    break;
            }
        }
    }

    /* 处理返回值 */
    *returnSize = peopleSize;  
    *returnColumnSizes = peopleColSize;
    return resort_people;
}

```
