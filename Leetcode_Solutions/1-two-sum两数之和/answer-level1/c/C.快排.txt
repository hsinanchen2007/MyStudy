### 解题思路
1.对所给数组快排变成有序数组（同时设置一个数组id表示交换后的序号）
2.i指向数组尾部，j指向数组头部，比较nums[i]+nums[j]与target的大小
3.若大，则i--，相等则通过数组id找到原序号返回，否则j++;

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void quick(int *nums,int *id,int begin,int end,int numsSize){
     if(begin>=end) return ;
     int flag=1;int pivot=nums[begin];int pivot1=id[begin];
     int i,j;
    for(i=begin,j=end;i<j;){
        if(flag){
          if(nums[j]>=pivot) j--;
          else {nums[i]=nums[j];id[i]=id[j];
          flag=0;i++;}
        }
        else{
          if(nums[i]<=pivot) i++;
          else {nums[j]=nums[i];id[j]=id[i];
          flag=1;j--;} 
        }
    }
    nums[i]=pivot;id[i]=pivot1;
    quick(nums,id,begin,i-1,numsSize);quick(nums,id,i+1,end,numsSize);
    
 }
 void quicksort(int *nums,int *id,int numsSize){
     quick(nums,id,0,numsSize-1,numsSize);
 }
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
      int *id=(int *)malloc(numsSize*sizeof(int));
      for(int i=0;i<numsSize;i++) id[i]=i;
      quicksort(nums,id,numsSize);
      int *s=(int *)malloc(2*sizeof(int));
      for(int i=numsSize-1,j=0;j<i;){
            if(nums[j]+nums[i]==target){
              s[0]=id[j];s[1]=id[i];
              *returnSize=2;
              return s;
            }
           else if(nums[j]+nums[i]>target) i--;
           else j++;
        
      }
       
       return NULL;
}













```