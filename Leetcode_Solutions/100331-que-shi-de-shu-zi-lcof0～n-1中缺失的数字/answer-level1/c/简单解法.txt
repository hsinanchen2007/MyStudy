先求这n个数之和，然后减去数组中所有数字之和。返回差值。

int missingNumber(int* nums, int numsSize){
int result=0;
for(int i=0;i<=numsSize;i++){
result=result+i;
}
for(int i=0;i<numsSize;i++){
result=result-nums[i];
}

return result;
}