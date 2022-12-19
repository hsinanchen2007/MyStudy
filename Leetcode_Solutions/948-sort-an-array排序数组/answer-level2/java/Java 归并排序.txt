### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        if(nums==null){
            return new int[]{};
        }
        int[] tmp = new int[nums.length];
        mergeSort(nums,0,nums.length-1,tmp);
        return nums;
    }
    public void mergeSort(int []nums,int start,int end,int[]tmp){
        if(start>=end){
            return;
        }
        int mid=start+(end-start)/2;
        mergeSort(nums,start,mid,tmp);
        mergeSort(nums,mid+1,end,tmp);
        Merge(nums,start,mid,end,tmp);
    }
    public void Merge(int []nums,int start,int mid,int end,int[]tmp){
        int leftindex=start;
        int rightindex=mid+1;
        int index=start;
        while(leftindex<=mid && rightindex<=end){
            if(nums[leftindex]<nums[rightindex]){
                tmp[index++]=nums[leftindex++];
            }else{
                tmp[index++]=nums[rightindex++];
            }
        }
        while(rightindex<=end){
            tmp[index++]=nums[rightindex++];
        }
        while(leftindex<=mid){
            tmp[index++]=nums[leftindex++];
        }
        for(int i=start;i<=end;i++){
            nums[i]=tmp[i];
        }
    }
}
```