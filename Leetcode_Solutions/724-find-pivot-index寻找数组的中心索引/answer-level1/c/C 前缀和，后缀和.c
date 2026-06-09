### 解题思路
使用前缀和和后缀和

### 代码

```c
int pivotIndex(int* nums, int numsSize){
    
    //定义两个数组，一个存前缀和，一个存后缀和
    if((nums == NULL) || (numsSize == 0)){
        return -1;
    }
    if (numsSize == 1) {
        return 0;
    }

    int pivotIndex = -1;

    int * prevArray = (int *)malloc(sizeof(int) * numsSize);
    memset(prevArray, 0, sizeof(int) * numsSize);
    int * suffixArray = (int *)malloc(sizeof(int) * numsSize);
    memset(suffixArray, 0, sizeof(int) * numsSize);
    *prevArray = *nums;
    //遍历数组，得到前缀和
    for(int i = 1; i < numsSize; i++) {
        *(prevArray + i) = *(prevArray + i - 1) + *(nums + i);
    }
    *(suffixArray + numsSize - 1) = *(nums + numsSize - 1);
    //遍历数组得到后缀和
    for(int i = numsSize - 2; i >=0; i--) {
      *(suffixArray + i) =  *(suffixArray + i + 1) +  *(nums + i);
    }
    //遍历数组得到，中心索引
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            if (*(suffixArray + 1) == 0) {
                pivotIndex = 0;
                break;
            }
        } else if (i == numsSize - 1) {
            if (*(prevArray + numsSize -2) == 0) {
                pivotIndex = numsSize - 1;
                break;
            }
        } else {
            if (*(prevArray + i -1) == *(suffixArray + i + 1)) {
                pivotIndex = i;
                break;
            }
        }
    }
    return pivotIndex;
}
```