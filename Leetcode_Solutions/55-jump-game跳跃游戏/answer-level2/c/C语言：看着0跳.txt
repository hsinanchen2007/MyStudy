```
bool canJump(int* nums, int numsSize){
    if (numsSize == 1)//[0]
        return true;
    if (nums[0] == 0)
        return false;
    else{
        for (int i = 1; i < numsSize - 1; i++){
            if (nums[i] == 0){
                int j = i - 1;
                for (; j >= 0; j--){
                    if (nums[j] > i - j)
                        break;
                }
                if (j == -1)
                    return false;
            }
        }
    }
    return true;
}
```
