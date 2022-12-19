### 解题思路
这道题的本质就是归并排序。大佬已经讲解了归并排序和这道题目的解法。
https://zhuanlan.zhihu.com/p/107280674

### 代码

```java
class Solution {
    int count=0;
    public int reversePairs(int[] nums) {
        mergeSort(nums,0,nums.length-1);
        return count;
    }
    public void mergeSort(int[] nums,int start,int end){
        if(start<end){
            //int mid=(start+end)/2;
            int mid=start+((end-start)>>1);
            mergeSort(nums,start,mid);
            mergeSort(nums,mid+1,end);
            //合并
            merge(nums,start,mid,end);
        }
    }
    public void merge(int[] nums,int start,int mid,int end){
        int[] temp=new int[end-start+1];
        int p1=start;
        int p2=mid+1;
        int p=0;
        while(p1<=mid && p2<=end){
            if(nums[p1]<=nums[p2]){
                temp[p++]=nums[p1++];
            }else{
                count=count+mid-p1+1;
                temp[p++]=nums[p2++];
            }
        }
        while(p1<=mid){
            temp[p++]=nums[p1++];
        }
        while(p2<=end){
            temp[p++]=nums[p2++];
        }
        for(int i=0;i<temp.length;i++){
            nums[i+start]=temp[i];
        }
    }
}
```