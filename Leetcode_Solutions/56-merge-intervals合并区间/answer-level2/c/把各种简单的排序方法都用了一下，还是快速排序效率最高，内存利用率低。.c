### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 //冒泡排序
void bubble(int *a, int size){
    int i, j, t;
    for(i = 0; i < size - 1; i ++){
        for(j = 0; j < size -i - 1; j ++){
            if(a[j] > a[j + 1]){
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
//插入排序
void insert(int *a, int size){
    int i, j, t, tmp;
    for(i = 1; i < size; i ++){
        j = i - 1;
        while(j >= 0 && a[j] > a[j + 1]){
            tmp = a[j + 1];
            a[j + 1] = a[j];
            a[j] = tmp;
            j --;
        }
    }
}
//归并排序
void merge1(int *ins, int p, int q, int r){
    int *a = NULL, *b = NULL, len1, len2, i, j , k;

    len1 = q - p + 1;
    len2 = r - q;
    a = malloc(sizeof(int) * len1);
    b = malloc(sizeof(int) * len2);
    if(NULL == a || NULL == b)return;
    for(i = 0; i < len1; i ++){
        a[i] = ins[p + i];
    }
    for(i = 0; i < len2; i ++){
        b[i] = ins[q + 1 + i];
    }

    j = 0;
    k = 0;
    for(i = 0; i < len1 + len2; i ++){
        if(j >= len1 && k >= len2){
            break;
        }
        if(j < len1 && k < len2){
            if(a[j] <= b[k]){
                ins[p + i] = a[j];
                j ++;
            }
            else{
                ins[p + i] = b[k];
                k ++;
            }
        }else if(j < len1){
            ins[p + i] = a[j];
            j ++;
        }else{
            ins[p + i] = b[k];
            k ++;
        }
    }
    
    if(a)free(a);
    if(b)free(b);
    return;
}

void merge_sort(int *ins, int p, int q){
    //int i;
    if(p >= q)return;
    //i = (p + q)/2;
    merge_sort(ins, p, (p + q)/2);
    merge_sort(ins, (p + q)/2 + 1, q);
    merge1(ins, p, (p + q)/2, q);
    return;
}
//快速排序
int partion(int *ins, int p, int q){
    int x, i ,j, t;
    
    x = ins[q];
    j = p - 1;
    for(i = p; i < q; i ++){
        if(ins[i] <= x){
            j ++;
            t = ins[i];
            ins[i] = ins[j];
            ins[j] = t;
        }
    }
    
    t = ins[i];
    ins[i] = ins[j + 1];
    ins[j + 1] = t;

    return j + 1;
}

void quick(int *ins, int p, int q){
    int i;
    if(p >= q)return;
    i = partion(ins, p, q);
    quick(ins, p , i - 1);
    quick(ins, i + 1, q);
    return;
}
//系统的排序函数
 int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int i;

    int *start = malloc(intervalsSize * sizeof(int));
    int *end = malloc(intervalsSize * sizeof(int));
    *returnColumnSizes = (int *)malloc(intervalsSize * sizeof(int));
    int **re = (int **)malloc(intervalsSize * sizeof(int *));

    for(i = 0; i < intervalsSize; i ++){
        re[i] = (int *)malloc(*intervalsColSize * sizeof(int));
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    *returnSize = 0;
    quick(start, 0, intervalsSize - 1);
    quick(end, 0, intervalsSize - 1);
    for(i = 0; i < intervalsSize; i ++){
        re[*returnSize][0] = start[i];
        for(; i< intervalsSize - 1; i ++){
            if(end[i] < start[i + 1]){
                break;
            }
        }
        re[*returnSize][1] = end[i];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize) ++;
    }

    free(start);
    free(end);
    return re;
}
```