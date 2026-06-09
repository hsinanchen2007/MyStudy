```
/*方法1 创建一个新的数列，在新数列中按要求的顺序写入后，cpy一下；
void rotate(int* nums, int numsSize, int k){

    int *ret = (int *)malloc(sizeof(int)*numsSize);
    for (int i = 0 ; i < numsSize; i++){
        ret[(i + k) % numsSize] = nums[i];        
    }
    memcpy(nums,ret,sizeof(int)*numsSize);
    return;
}
*/
/*方法2 最后一个算例超时；每次向后移动一位，一共移动k次（思考过单点按k步长连续替换发现如果k为numsSize的约数，会进入循环，太麻烦就不想了）
void rotate(int* nums, int numsSize, int k){
    for (int n = 0; n < k; n++){    
        int tmp = nums[numsSize - 1];
        for (int i = numsSize - 1;i > 0; i--){
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
    return;
}
*/
/*方法3 将numsSize中k位的数组放置在ret中，然后numsSize后移，再将numsSize放在前面补齐。
void rotate(int* nums, int numsSize, int k){
    int *ret = (int *)malloc(sizeof(int)*k);
    int i = 0;
    while (i < k){
        ret[k - 1 - i] = nums[(2*numsSize - 1 - i) % numsSize];
        i++;
    }
    for (int j = 0;j < numsSize - k; j++){
        nums[numsSize - 1 - j] = nums[numsSize - 1 - j - k];
    }
    for (int j = 0;j < k; j++){
        nums[j % numsSize] = ret[j];
    }
    return;
}
*/
```
