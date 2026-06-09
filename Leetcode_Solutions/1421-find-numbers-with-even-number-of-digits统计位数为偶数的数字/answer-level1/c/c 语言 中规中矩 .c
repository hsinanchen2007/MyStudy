```
int findNumbers(int* nums, int numsSize){
    int r = 0;
    while(numsSize > 0){
        int item = nums[--numsSize];
        int len = 0;
        while(item > 0){
            item = (item - item % 10)/10;
            len++;
        }
        if(!(len & 1)){
            r++;
        }
    }
    return r;
}

```
