![图片.png](https://pic.leetcode-cn.com/671ce259024cca14d5631a83e27cc4f23ca804b4d3eb773d23b7726fb6fd93ba-%E5%9B%BE%E7%89%87.png)


```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 typedef struct{
     int arrnum; //存放原数字
     int local; //存放排序后结果
 }test;

int tp(int start, int end, test *arr, int tmp){
    if(arr[(start + end) / 2].arrnum == tmp || start == end){
        return arr[(start + end) / 2].local;
    }else if(arr[(start + end) / 2].arrnum > tmp){
        return tp(start, (start + end) / 2 - 1, arr, tmp);
    }else if(arr[(start + end) / 2].arrnum < tmp){
        return tp((start + end) / 2 + 1, end, arr, tmp);
    }
    return 0;
}

 int cmp(const void * a, const void * b){
     return *(int*)a-*(int*)b;
 }

int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
     *returnSize = arrSize;
    if(arrSize == 0){
        int num[] = {};
        return num;
    }
    int *tmp, i;
    int *arr1;
    arr1 = (int*)malloc(sizeof(int) * arrSize);
    memcpy(arr1,arr,sizeof(int)*arrSize);

    qsort(arr, arrSize, sizeof(int), cmp);
    
    test *arr2;
    arr2 = (test*) malloc(sizeof(test) * arrSize);

    arr2[0].arrnum = arr[0];
    arr2[0].local = 1;
    for(i = 1; i < arrSize; i++){
        if(arr[i] == arr[i - 1]){
            arr2[i].local = arr2[i - 1].local;
        }else{
            arr2[i].local = arr2[i - 1].local + 1;
        }
        arr2[i].arrnum = arr[i];
    }
    int k;
    for(i = 0; i < arrSize; i++){
        arr1[i] = tp(0, arrSize - 1, arr2, arr1[i]);
    }

    return arr1;
}



```

