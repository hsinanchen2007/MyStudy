### 解题思路
归并排序

### 代码

```java
class Solution {
    int count = 0;
    //归并排序
    public int reversePairs(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        mergeSort(nums,0,nums.length-1);
        return count;
    }
    //分
    public void mergeSort(int[] nums,int start,int end){
        int mid = (start + end) / 2;
        if(start < end){
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            merge(nums,start,mid,end);
        }
    }
    //合并
    public void merge(int[] nums,int start,int mid,int end){
        int[] arr = new int[end - start + 1];
        int midIdx = mid + 1;
        int s = start;
        int c = 0;
        while(start <= mid && midIdx <= end){
            if(nums[start] <= nums[midIdx]){
                //顺序正确
                arr[c++] = nums[start++];
            }else{
                arr[c++] = nums[midIdx++];
                count += mid + 1 - start;
            }
        }
        //将剩余的数组放入临时数组arr中
        while(start <= mid){
            arr[c++] = nums[start++];
        }
        while(midIdx <= end){
            arr[c++] = nums[midIdx++];
        }
        for(int num : arr){
            nums[s++] = num;
        }
    }
}
```