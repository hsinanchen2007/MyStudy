### 解题思路
双重循环
将当前数与后面一个数比较，如果当前的数为0，后面一个数不为0，那么就交换。只要发生交换动作就退出内层循环（因为当前数已经不为0）

### 代码

```c
void swap(int*nums ,int i,int j){
    int temp=nums[i];
    nums[i]=nums[j];
    nums[j]=temp;
}



void moveZeroes(int* nums, int numsSize){
   int i,j;
   for(i=0;i<numsSize-1;i++){
       for(j=i+1;j<numsSize;j++){
           if(nums[i]==0&&nums[j]!=0){
               swap(nums,i,j);
               break;
           }
       }
   }



