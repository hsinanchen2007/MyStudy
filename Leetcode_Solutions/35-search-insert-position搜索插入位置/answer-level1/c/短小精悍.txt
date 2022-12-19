int searchInsert(int* nums, int numsSize, int target){
int i,a;
if(target>nums[numsSize-1])
    a=numsSize;
for(i=0;i<numsSize;i++){
if(target<=nums[i]){
    a=i;break;
}
}return a;
}
