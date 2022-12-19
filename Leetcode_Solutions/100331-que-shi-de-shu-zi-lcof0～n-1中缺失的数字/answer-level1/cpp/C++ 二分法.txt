
如果中间元素的值和下标相等，那么下一轮查找只需要查找右半边；
如果中间元素的值和下标不相等，并且它前面一个元素和它的下标相等，则中间的这个数字正好是第一个值和下标不相等的元素，它的下标就是在数组中不存在的数字；
如果中间元素的值和下标不相等，并且它前面一个元素和它的下标不相等，那么下一轮查找只需要查找左半边
```
 int missingNumber(vector<int>& nums) {
       int left=0,right=nums.size()-1;
       while(left<=right){
           int mid=left+(right-left)/2;
           if(nums[mid]!=mid){
               if(mid==0||nums[mid-1]==mid-1){
                   return mid;
               }
               right=mid-1;
           }
           else left=mid+1;
       }
       if(left==nums.size()) return left;
       else return -1;
    }
```
