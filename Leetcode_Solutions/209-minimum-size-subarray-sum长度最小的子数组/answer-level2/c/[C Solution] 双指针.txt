### 解题思路
此处撰写解题思路

### 代码

```c
#define MIN(a,b)(a>b?b:a);


// 暴力解题，c不会超时
/*
int minSubArrayLen(int s, int* nums, int numsSize){
    if(numsSize <= 0){
        return 0;
    }

    int min = INT_MAX;

    for(int i = 0 ; i < numsSize ; i++){
        int sum = 0;
        for(int j = i; j < numsSize ; j++){
            sum += nums[j];
            if(s <= sum){
                min = MIN(min , (j - i + 1));
                break;
            }
        }
    }

    return min == INT_MAX ? 0 : min;
}*/

int minSubArrayLen(int s, int* nums, int numsSize){
     if(numsSize <= 0){
        return 0;
    }

    int min = INT_MAX , left = 0 , sum = 0;

    for(int i = 0 ; i < numsSize ; i++){
        sum += nums[i];
        while(s <= sum){
            min = MIN(min , (i  - left + 1));
            sum -= nums[left++];
        }
    }
    return min == INT_MAX ? 0 : min;
}
```