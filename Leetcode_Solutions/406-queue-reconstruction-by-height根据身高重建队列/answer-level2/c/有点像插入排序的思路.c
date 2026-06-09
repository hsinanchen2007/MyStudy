### 解题思路
此处撰写解题思路

### 代码

```c

// 二维数组排序：规则是：按每一行的第一个元素由大到小的顺序排，如果第一哥元素相同，则按第二个元素由小到大排
//排序的结果是升高由高到低排好序，并且，相同升高的同学也都排好了
int CmpFun(const void *a, const void *b)
{
    int **p1 = (int **)a;
    int **p2 = (int **)b;
    if ((*p1)[0] != (*p2)[0]) {
        return (*p2)[0] - (*p1)[0]; 
    } else {
        return (*p1)[1] - (*p2)[1]; 
    }
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int **resut = (int **)malloc(sizeof(int *) * peopleSize);
    if (resut == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < peopleSize; i++) {
        resut[i] = (int *)malloc(sizeof(int) * 2);
        memset(resut[i], 0, sizeof(int) * 2);
    }

    qsort(people, peopleSize, sizeof(int) * 2, CmpFun);

    int j = 0;
    int k = 0;
     for (i = 0; i < peopleSize; i++) {
         if (i == 0) {
             resut[i][0] = people[i][0];
             resut[i][1] = people[i][1];
             continue;
         }

        // 处理people[i]时，遍历之前已经排好的前i个元素
        for (j = 0; j < i; j++) {
            if (people[i][0] <= resut[j][0]) {
                if (people[i][1] != 0 && (j + 1 != people[i][1])) { // 如果people[i]的升高前面有同学，则找出people[i]  应该出现的位置。否则，直接把people【i】放在第一个位置上，因为他前面没有同学了。
                    continue;
                }
                break;
            } 
            break;
        }

    int kcurToMove; // resut数组中要移动位置的元素位于第几个位置上。

        if (people[i][1] == 0) {
            kcurToMove = 0; //resut数组中的元素从第0个元素开始依次向后移动位置
        } else {
            kcurToMove = j + 1;
        }
        
        int temphpre = resut[kcurToMove][0];
        int tempkpre = resut[kcurToMove][1];
        int temphk ; //临时保存要被覆盖的元素
        int tempkk; 
        
        for(k = kcurToMove; k < peopleSize - 1; k++) {
            temphk = resut[k + 1][0];
            tempkk = resut[k + 1][1];
            resut[k + 1][0] = temphpre;
            resut[k + 1][1] = tempkpre; 
            temphpre = temphk;
            tempkpre = tempkk;
        }
        resut[kcurToMove][0] = people[i][0];
        resut[kcurToMove][1] = people[i][1];
         
    }   

    *returnSize = peopleSize;
    * returnColumnSizes = (int *)malloc(sizeof(int) * peopleSize);
    for (i = 0; i < peopleSize; i++) {
        (* returnColumnSizes)[i] = 2;
    }

    return resut;

}
```