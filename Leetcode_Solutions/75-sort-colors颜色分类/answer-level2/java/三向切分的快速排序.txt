### 解题思路
划分成三个区间
<V
=V
\>V 

lt表示小于区间的最右边指针
gt表示大于区间的最左边指针
i 表示还是进行排序的区间


### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        sort(nums,0,nums.length-1);
    }
    // 快速排序的三向切分排序
    private void sort(int nums[],int lo,int hi){
        if(lo>hi) return;
        int lt=lo,i=lo+1,gt=hi;
        int flag=nums[lo];
        while(i<=gt){
            int cmp=nums[i]-flag;
            if(cmp<0) exch(nums,lt++,i++);
            else if(cmp>0) exch(nums,i,gt--);
            else i++;
        }
        // 递归实现
        sort(nums,lo,lt-1);
        sort(nums,gt+1,hi);
    }
    
    private void exch(int nums[],int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
    }
}
```