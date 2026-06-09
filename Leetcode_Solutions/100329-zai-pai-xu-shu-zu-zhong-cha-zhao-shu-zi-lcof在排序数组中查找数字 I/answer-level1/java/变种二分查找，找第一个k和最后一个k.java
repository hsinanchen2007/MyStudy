用二分查找的方法分别获取第一个target和最后一个target的索引，然后计算总个数。
这里为了巩固二分查找的两种实现方法（循环与递归）。firstSearch用递归实现，lastSearch用循环实现。

代码如下：
```
class Solution {
    
    private int[] nums;
    private int target;
    public int search(int[] nums, int target) {
        if(nums==null || nums.length==0) return 0;
        this.nums = nums;
        this.target = target;
        int first = firstSearch(0,nums.length-1);
        int last = -1;
        if(first!=-1){
            last = lastSearch(0,nums.length-1);
            return last-first+1;
        }
        return 0;
    }

    //递归实现
    private int firstSearch(int start, int end){
        if(start>end) return -1;
        int mid = start+(end-start)/2;
        if(nums[mid]<target){
            return firstSearch(mid+1, end);
        }else if(nums[mid]>target){
            return firstSearch(start, mid-1);
        }else{
            if(mid==0 || nums[mid-1]!=target) return mid; //条件满足则说明当前就是第一个target
            else return firstSearch(start,mid-1); //否则第一个target一定在前半部分
        }
    }

    //循环实现
    private int lastSearch(int start, int end){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]<target){
                start = mid+1;
            }else if(nums[mid]>target){
                end = mid-1;
            }else{
                if(mid==nums.length-1 || nums[mid+1]!=target) return mid; //条件满足则说明当前就是最后一个target
                else start = mid+1;  //否则最后一个target一定在后半部分
            }
        }
        return -1;
    }
}
```
