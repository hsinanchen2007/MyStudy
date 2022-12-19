### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ccee5a110b69291edbef8d89964523f210f611da91ebfb44c73ded2afde97bf8-image.png)

### 代码

```c
int minSubArrayLen(int s, int* nums, int numsSize){
    if(s < 1 || nums == NULL || numsSize  < 1) return 0;
    
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 2));
    if(sum == NULL) return 0;

    sum[0] = 0;
    for(int i =0; i<numsSize; i++){
        sum[i+1] = sum[i] + nums[i];
    }

    int length = numsSize + 2;
    int left = 0, right = 0;

    
    while(right < numsSize){
        while(left < right && sum[right + 1] - sum[left +1] >= s){
            left ++;
        }

        if(sum[right + 1] - sum[left] >= s){
            int tmp = right - left + 1;
            length = tmp < length ? tmp : length;
        }

        right++;
        if(right - left + 1 > length){
            left++;
        }
    }
    
    if(length <= numsSize)
        return length;
    else
        return 0;
}
```