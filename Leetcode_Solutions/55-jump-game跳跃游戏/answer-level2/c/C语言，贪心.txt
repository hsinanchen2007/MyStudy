### 解题思路
假设当前点是可以到达的，那么最大长度一定比当前点要大，否则，就是跳不大最后一个的说法了。
如果顺利完成的话，最大跳转长度一定比数组长度要长

### 代码

```c


bool canJump(int* nums, int numsSize){
    if (numsSize == 0) return false;
    int * maxjump_arr = (int *)malloc(sizeof(int) * numsSize);
    int max_jump = 0;
    memset(maxjump_arr, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        maxjump_arr[i] = i + nums[i];
    }


    for (int i = 0; i < numsSize; i++) {
        if (maxjump_arr[i] > max_jump) {
            max_jump = maxjump_arr[i];
        }
        if(i >= max_jump){ 
            break;
        }
    }
    //printf("%d ", max_tmp);
    if (max_jump >= numsSize -1 ) return true;

    return false;
}


```