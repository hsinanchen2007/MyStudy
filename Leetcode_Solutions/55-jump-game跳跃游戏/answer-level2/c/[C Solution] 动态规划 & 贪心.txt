### 解题思路
此处撰写解题思路

### 代码

```c
// 动态规划，自底向上, 672ms

#define MIN(a,b)((a)<(b) ? (a) : (b))
bool canJump(int* nums, int numsSize){

    if(numsSize <= 0){
        return true;
    }
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    memset(arr,0,sizeof(int)*numsSize);

    arr[numsSize-1] = 1;

    for(int i = numsSize -2 ; i >= 0 ; i--){
        int minStep = MIN(i+nums[i],numsSize -1);
        for(int j = i + 1 ; j <= minStep; j++){
            if(arr[j] == 1){
                arr[i] = 1;
                break;
            }
        }
    }

    return arr[0];
}

// 贪心算法 16ms
bool canJump(int* nums, int numsSize){
     int lastPos = numsSize - 1;
        for (int i = numsSize - 1; i >= 0; i--) {
            if (i + nums[i] >= lastPos) {
                lastPos = i;
            }
        }
        return lastPos == 0;
}
```