![image.png](https://pic.leetcode-cn.com/156bc16fc5434d6c9fb8f97beaefbc1fa6bc0955649dafebe10ab9687bd28ca1-image.png)

```
int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

bool SubFucDFS(int* nums, int numsSize, int *numsFlag, int sumTmp, int sum, int index) {
    int i;
    bool returnValue;

    if (numsFlag[index] == 1) {
        return false;
    }

    sum = sum + nums[index];

    printf("index: %d, sum: %d\n", index, sum);
    if (sum > sumTmp) {
        return false;
    }
    if (sum == sumTmp) {
        return true;
    }
    
    for (i = index + 1; i < numsSize; i++) {
        returnValue = SubFucDFS(nums, numsSize, numsFlag, sumTmp, sum, i);
        if (returnValue == false) {
            //i = numsSize;
            ;
        } else {
            numsFlag[i] = 1;
            return true;
        }
    }
    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k){
    if ((nums == NULL) || (numsSize == 0)) {
        return false;
    }

    int *numsFlag = (int *)malloc(numsSize * sizeof(int));
    
    int sum = 0;
    int index = 0;
    int i;
    int kCpy = 0;
    bool returnValue = true;
    int cnt = 0;
    int j = 0;
    bool bool1 = false;

    if ((nums == NULL) || (numsSize == 0)) {
        return false;
    }
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int sumTmp = 0;
    for (i = 0; i < numsSize; i++) {
        sumTmp = sumTmp + nums[i];
    }
    if (sumTmp % k != 0) {
        return false;
    }
    sumTmp = sumTmp / k;
    if (nums[numsSize - 1] > sumTmp) {
        return false;
    }

    printf("sumTmp: %d\n", sumTmp);
    memset(numsFlag, 0, numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        if (numsFlag[i] == 0) {
            bool1 = SubFucDFS(nums, numsSize, numsFlag, sumTmp, sum, i);
            if (bool1 == true) {
                numsFlag[i] = 1;
                cnt++;
            } else {
                return false;
            }
            
            for (j = 0; j < numsSize; j++) {
                printf("i: %d, numsFlag[%u]: %d\n", i, j, numsFlag[j]);
            }
            printf("\n");
            
        }
    }

    printf("cnt: %d, k: %d\n", cnt, k);
    for (i = 0; i < numsSize; i++) {
        printf("numsFlag[%d]: %d\n", i, numsFlag[i]);
        if (numsFlag[i] == 0) {
            returnValue = false;
        } 
    }
  
    if ((returnValue == true) && (cnt == k)) {
        return true;
    }

    return false;
}
```
