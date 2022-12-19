### 解题思路
此处撰写解题思路

### 代码
方法一：暴力递归，直接超时。从后往前循环找到能跳到numsSize的位置，在递归判断找到的这些位置能否也能被跳到。
```
bool canJump(int* nums, int numsSize){
    if(numsSize<2){
        return true;
    }else{
        for(int i=numsSize-2;i>=0;i--){
            if(nums[i]+i >= numsSize-1){
                if(canJump(nums,i+1)){
                    return true;
                }
            }
        }
    }
    return false;
}
```

方法二：动态规划，
```c
bool canJump(int* nums, int numsSize){
    if(numsSize == 1){
        return true;
    }
    int sign[numsSize]; //sign[i] = 1;表示能走到i+1的位置
    sign[0] = 1;
    for(int i=1;i<numsSize;i++){
        sign[i] = 0;
    }
    int front = 0;
    int rear = 1;//记录下一个该判断能否到达的位置
    for(front;front<rear;front++){
        for(int i=rear-front;i<=nums[front];i++){
            sign[rear++] = 1;
            if(rear == numsSize){
                return (sign[numsSize-1]==1?true:false);
            }
        }
    }
    return (sign[numsSize-1]==1?true:false);
}
```
方法三：通过动态规划我们发现可以直接只记录能跳到的最远的位置
```
bool canJump(int* nums, int numsSize){
    int far = 0;  //记录能跳到的最远的位置
    for(int i=0;i<=far;i++){
        far = (nums[i]+i>far?nums[i]+i:far);
        if(far>=numsSize-1){
            return true;
        }
    }
    return false;
}

```
