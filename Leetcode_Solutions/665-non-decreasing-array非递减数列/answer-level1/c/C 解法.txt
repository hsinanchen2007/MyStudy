
# 思路：
官方题解第三种方法

# 代码：
```
#define TRUE 1
#define FALSE 0

bool checkPossibility(int* nums, int numsSize){
    int count  = 0;
    
    for(int i = 1;i < numsSize && count < 2;i++){

        if(nums[i - 1] > nums[i]){ // 有非递减存在
            if(i - 1 != 0 && i != numsSize - 1){ 
            // 如果两个数的位置不在数列的边缘， nums[i - 2],nums[i - 1,]，nums[i],nums[i + 1]都存在
                if(nums[i-2] > nums[i] && nums[i-1] > nums[i+1]){
                   //如果nums[i - 2] 比 nums[i]大，则nums[i - 1]不能改
                   //如果nums[i - 1] 比 nums[i +1]大，则nums[i]不能改
                   //如果两个都不行，数列一定无法修改成非递减（此题给予的条件之下）
                    return FALSE;
                }else{
                    count++;
                }
            }else{
                //如果其中有一个数字在边缘，改变nums[i-1] = nums[i] 或者 nums[i] = nums[i-1]，数列依然非递减。
                count++;
            }
        }
    }

    if(count >= 2){
        return FALSE;
    }
    return TRUE;
}
```

