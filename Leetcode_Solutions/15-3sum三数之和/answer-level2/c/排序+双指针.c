
1、将三数之和分解为求解两数之和；
2、求解两数之和的时候，用排序+双指针会快一点；
3、最后就是在遍历的时候剔除相同的答案。

```
int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }
    int j = 0;
    int k = 0;
    int ind = 0;
    int sum = 0;
    int maxSize = numsSize * 6; //这个6是试出来的吧，5就过不了
    //int maxSize = 100000; //maxSize应该申请为多少比较合适，反正不能申请为固定值，至少是跟numsSize相关的一个值
    int columSize = 3;
    int **returnArr = (int **)malloc(maxSize * sizeof(int *));
    returnArr[ind] = malloc(sizeof(int) * 3);
    //for (int i = 0; i < maxSize; i++) {                        //用的时候再申请，可以省空间
        //returnArr[i] = (int *)malloc(columSize * sizeof(int));
    //}
    *returnColumnSizes = malloc(maxSize * sizeof(int));

    qsort(nums, numsSize, sizeof(int), comp);//用自带的排序

    for (int i = 0; i < (numsSize - 2); i++) {
        if ((i > 0) && nums[i] == nums[i-1]) {
            continue;
        }
        j = i + 1;
        k = numsSize - 1;
        sum = 0 - nums[i];
        while(j < k) {
            if ((nums[j] + nums[k]) > sum) {
                k--;
                if ((j < k) && (nums[k] == nums[k+1])) {
                   k--;
                }
            } else if ((nums[j] + nums[k]) < sum){
                j++;
                if ((j < k) && (nums[j] == nums[j-1])) {
                   j++;
                }
            } else {
                returnArr[ind][0] = nums[i];
                returnArr[ind][1] = nums[j];
                returnArr[ind][2] = nums[k];
                (*returnColumnSizes)[ind] = 3;
                ind++;
                returnArr[ind] = malloc(sizeof(int) * 3); //用的时候再申请，可以省空间
                j++;
                k--;
                while ((j < k) && (nums[k] == nums[k+1])) {
                   k--;
                }
                while ((j < k) && (nums[j] == nums[j-1])) {
                   j++;
                }
                
            }
        }
    }
    *returnSize = ind;
    return returnArr;
}

```


