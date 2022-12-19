### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        quickSort(nums,0,nums.length-1);
        return nums;
    }
    public void quickSort(int[] nums,int l,int r){
        if(l<r){
            int rand_pivot=(int)Math.random()*(r-l+1)+l;
            int[] p=partition(nums,l,r,rand_pivot);
            quickSort(nums,l,p[0]-1);
            quickSort(nums,p[1]+1,r);
        }
    }
    public int[] partition(int[] nums,int l,int r,int pivot){
        swap(nums,pivot,r);
        int less=l-1;
        int more=r;
        while(l<more){
            if(nums[l]<nums[r]){
                swap(nums,l++,++less);
            }else if(nums[l]>nums[r]){
                swap(nums,l,--more);
            }else{
                l++;
            }
        }
        swap(nums,more,r);
        return new int[]{less+1,more};
    }
    public void swap(int[] nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
```