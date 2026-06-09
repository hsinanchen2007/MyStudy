![image.png](https://pic.leetcode-cn.com/29408addde8405feef777c9e8b224268253fa12d646331f7ba8f223d07863881-image.png)

/* 从后往前检查元素是否为0*/
bool canJump(int* nums, int numsSize){
    if(nums==NULL || numsSize==0)
    return false;
    int i,j;
    for(i=numsSize-1;i>=0;i--){
        /* 元素为0时，逐次检查前面距离0元素j位的元素是否大于j，只有大于j才可能跳跃过0，否则无法通过0（即false） */
        if(nums[i]==0){
            /* 数组最后一个元素为0为特殊情况，无需跳过，到达即true，所以最后一位为0时不需要进行判断*/
            if(i!=numsSize-1){
                j=1;
                while(i){
                    i--;
                    if(nums[i]<=j)  /*无法跳过，同时j值加1，判断前一位元素 */
                        j++;
                    else{
                        i++;        /* 可以跳过，继续判断前面是否还有为0的元素*/
                        break;
                    }
                }
                if(i==0)            /*i==0：数组中没有元素可以跳过*/
                    return false;
            }
        }
    }
    return true;
}