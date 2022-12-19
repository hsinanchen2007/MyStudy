### 解题思路
找到转择点，还可以优化

### 代码

```c
int findMin(int* nums, int numsSize){
   int i=0,min=nums[0];

       while(nums[(i+numsSize)%numsSize]<=nums[(i+numsSize+1)%numsSize]&&(i<=numsSize)){
       i++;
       }
       min=nums[(i+numsSize+1)%numsSize];
       return min;
}
//找到转择点的元素就可以。
//如何找到转择点，
//判断第一个 元素与第二个元素的关系

```