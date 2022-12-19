执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.59%
的用户
内存消耗 :
38.1 MB
, 在所有 Java 提交中击败了
33.33%
的用户
```
class Solution {
    int min = Integer.MAX_VALUE;
    public int findMin(int[] nums) {
       calc(nums,0,nums.length-1);
        return min;
    }
    private void calc(int[] nums, int start, int end){
        if(start==end){
            min=nums[start];
            return;
        }else if(end-start==1){
            min=Math.min(nums[start],nums[end]);
            return;
        }
        int mid = (start+end)>>>1;
        if(nums[mid]==nums[start]){
            calc(nums,start+1,end);
        }else if(nums[mid]==nums[end]){
            calc(nums,start,end-1);
        }else if(nums[mid]>nums[start]&&nums[mid]>nums[end]){
            calc(nums,mid,end);
        }else if(nums[mid]<nums[start]&&nums[mid]<nums[end]){
            calc(nums,start,mid);
        }else if(nums[mid]>nums[start]&&nums[mid]<nums[end]){
            calc(nums,start,mid);
        }
    }
}
```
