```
class Solution {
    private void reverse(int []nums,int start,int end)
    {
         while (start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
    public void duplicateZeros(int[] arr) {
     int first=0,last=arr.length-1;
     while(first!=last)
     {
         if(arr[first]==0)
         {
             if(first!=last-1)
             {
             reverse(arr,++first,last);
             arr[first]=0;
             reverse(arr,first+1,last);
             }
             else
             arr[first+1]=0;
         }
         first++;
     }
    }
}
```
