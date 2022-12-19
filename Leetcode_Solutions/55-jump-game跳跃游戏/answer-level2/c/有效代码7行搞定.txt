![image.png](https://pic.leetcode-cn.com/a3b955016baa18bb057ebf3b4987d8e49953a7f8eb5c1841a9178d10a4135fb2-image.png)

从最后一个元素开始，如果当前元素跳跃的步数大于两个之间的距离，就认为可以跳到最后一步


bool canJump(int* nums, int numsSize){
    int i = numsSize-1;
    int j;
    int lastIndex=i;
    bool *ret= (bool*)malloc(numsSize*sizeof(bool));
    if(numsSize==1){
        return true;
    }
    for(i=numsSize-2;i>=0;i--){
        //j=i-1;
        if(nums[i]>=(lastIndex-i)) {
            ret[i] = true;
            lastIndex=i;

        } else {
            ret[i] = false;
        }

    }
    return ret[0];