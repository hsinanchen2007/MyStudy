### 解题思路
通过递归二分法直至数组长度小于一，比较即可得出结果

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        return halfCheck(0,nums.length-1,nums,target);
    }
    public int halfCheck(int start,int end,int[] nums,int target){
        if(end-start<=1){
            if(target<=nums[start]){return start;}
            if(target<=nums[end]){return end;}
            else {return end+1;}
        }
        int mid = (start+end)/2;
        if(nums[mid] == target){return mid;}
        if(nums[mid]>target){return halfCheck(start,mid,nums,target);}
        if(nums[mid]<target){return halfCheck(mid,end,nums,target);}
        return end;
    }
}
```