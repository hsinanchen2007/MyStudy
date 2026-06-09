### 解题思路
因为是升序的，所以和当前值比较，小于当前值找左部分，大于找右部分。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        return find(nums,0,nums.length-1,target);
    }

    public int find(int[] nums,int start,int end,int target){
        if(start>end) return -1;
        int index = (start + end)/2;
        int val = nums[index];
        if(val == target) return index;
        return val > target ? find(nums,start,index-1,target):find(nums,index+1,end,target);
    }
}
```