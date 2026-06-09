二分查找的查找过程是：将待查关键字与有序表的中间位置进行比较，若相等，查找成功，若小于，则只可能出现在有序表的前半部分，若大于则只可能出现在有序表的后半部分，因此，每经过一次比较，就将查找范围缩小一半，这样一直进行下去直到找到所需记录或者记录不在查找表中。
int search(int* nums, int numsSize, int target){
   int low=0;
   int high=numsSize-1;
   int mid=0;
   while(low<=high){
       mid=(low+high)/2;
       if(target==nums[mid])
           return mid;
       else if(target>nums[mid])
           low=mid+1;
       else high=mid-1;
   }
    
   return -1;
}
