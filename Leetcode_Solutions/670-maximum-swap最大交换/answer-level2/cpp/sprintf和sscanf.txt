```c
int maximumSwap(int num){
    char nums[10];
    sprintf(nums, "%d", num);
    int len = strlen(nums);
    for (int i = 0; i < len - 1; i++){
        int maxIndex = i;
        //从后往前，如1993，1和正数第二个9交换，而不是第一个
        for (int j = len - 1; j > i; j--){
            if (nums[j] > nums[maxIndex]){
                maxIndex = j;
            }
        }
        /*从前往后
        for (int j = i + 1; j < len; j++){
            if (nums[j] >= nums[maxIndex]){
                maxIndex = j;
            }
        }
        //98368,这种情况第一个8和第二个8不必交换
        if (nums[i] == nums[maxIndex]){
            continue;
        }
        */
        //nums[i]后存在比它大的数字，两者交换
        if (maxIndex != i){
            int temp = nums[i];
            nums[i] = nums[maxIndex];
            nums[maxIndex] = temp;
            sscanf(nums, "%d", &num);
            break;
        }
    }
    return num;
}
```