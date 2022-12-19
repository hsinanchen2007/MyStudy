### 解题思路
此处撰写解题思路

### 代码

```java
//快速排序进行解决吧
class Solution {
    public int findKthLargest(int[] nums, int k) {
         if(k>nums.length){
             return -1;
         }
         k=nums.length-k;
         int lo=0;
         int hi=nums.length-1;
         
         while(lo<hi){
             int index=partition(nums,lo,hi);
             if(index==k){
                 return nums[index];
             }else if(index>k){
                 hi=index-1;
             }else{
                 lo=index+1;
             }
         }
         return nums[lo]; 
    }
    public int partition(int[]arr,int left,int right){
           int temp=arr[left];
           while(left<right){
               while(left<right&&(arr[right]>temp)){
                   right--;
               }
               if(left<right){
                   arr[left]=arr[right];
                   left++;
               }
               while(left<right&&arr[left]<=temp){
                   left++;
               }
               if(left<right){
                  arr[right]=arr[left];
                 right--;
               }
           }
           arr[left]=temp;
           return left;
    }
}
```