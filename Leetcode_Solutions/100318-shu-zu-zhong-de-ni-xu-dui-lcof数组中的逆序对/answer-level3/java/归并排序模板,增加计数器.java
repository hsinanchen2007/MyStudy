### 解题思路
归并排序：
1.把长度为n的输入序列分成两个长度为n/2的子序列
2.对这两个子序列分别采用归并排序
3.将两个排列好的子序列合并成一个最终的排序序列。

### 代码

```java
class Solution {
    private int count=0;
    public int reversePairs(int[] nums) {
        if(nums.length<2){
            return 0;
        }
        mergeSort(nums,0,nums.length-1);
        return count;
    }
    
    public void mergeSort(int[] nums,int left,int right){
        if(right<=left){
            return;
        }
        int mid=(left+right)>>1;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    public void merge(int[] nums,int left,int mid,int right){
        int[] temp=new int[right-left+1];
        int i=left,j=mid+1,k=0;
        while(i<=mid&&j<=right){
            // 增加计数器：两个序列各自有序 故 nums[i] > nums[j]，nums[i]->num[mid] 都大于j
            if(nums[i]>nums[j]){
                count+=(mid-i+1);
            }
            temp[k++]=nums[i]<=nums[j]?nums[i++]:nums[j++];
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=right){
            temp[k++]=nums[j++];
        }
        for(int p=0;p<temp.length;p++){
            nums[left+p]=temp[p];
        }
    }
}
```