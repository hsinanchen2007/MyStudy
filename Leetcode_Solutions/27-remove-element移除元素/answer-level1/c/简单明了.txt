flag表示有多少个这样的目标值，输出长度就是numsSize-flag
遍历一遍数组，在i处发现找到目标值flag次，就把数组下一个值，往前移动flag位

int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int flag = 0;
    for(i = 0;i<numsSize;i++){
        if(nums[i] == val){
            flag ++;
            continue;
        }
        nums[i-flag] = nums[i];
    }
    return numsSize-flag;
}