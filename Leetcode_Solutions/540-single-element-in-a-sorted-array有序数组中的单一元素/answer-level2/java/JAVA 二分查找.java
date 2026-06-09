
从题目的复杂度要求推算出二分查找的解法
每次二分查找一部分数组，从中位数开始，如果中位数左右都和中位数不等，则中位数是被查数
然后边界情况好好判断一下，如果中位数的左边和中位数相等下一次查找范围里要排除。

java 0ms 100%
时间复杂度O(logn) n为数组长度，空间复杂度O(1)
```
class Solution {
    boolean find=false;
    int n=0;
    public int singleNonDuplicate(int[] nums) {
        if(nums.length == 1)return 1;
        help(nums,0,nums.length-1);
        return n;
    }

    public void help(int[] nums,int s,int e){
        if(find) return;
        if(s>nums.length-1 || e<0 || s>e) return;
        if(s==e){
            n = nums[s];
            return;
        }
        int mid = (s+e)/2;
        if(( mid-1>=0 && nums[mid-1] != nums[mid] )  && (mid+1<=nums.length-1 && nums[mid+1] != nums[mid])){
            find = true;
            n=nums[mid];
        }else{
            if(mid-1>=0 && nums[mid-1] == nums[mid]){
                help(nums,s,mid-2);
                help(nums,mid+1,e);
            }
            if(mid+1<=nums.length && nums[mid+1] == nums[mid]){
                help(nums,s,mid-1);
                help(nums,mid+2,e);
            }
        }
        return;
    }
}
```
