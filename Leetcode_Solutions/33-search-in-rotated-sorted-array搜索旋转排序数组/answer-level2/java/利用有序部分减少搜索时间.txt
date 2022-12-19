### 解题思路
4，5，6，7，0，1，2 有两部分有序，若target<nums[0]，说明target属于第二有序部分，遍历；终止有三种情况：1.找到target，2.未找到target，但是target值属于nums.MIN和nums.MAX之间，3.target<nums.MIN。
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums.length == 0) return -1;
        int len = nums.length;
        if(target < nums[0]){
            for(int i= len-1;i>=0;i--){
                if(target == nums[i]) return i;
                if(target > nums[i]) return -1;
            }
            return -1;
        }
        if(target > nums[0]){
            for(int i=0;i<len;i++){
                if(target == nums[i]) return i;
                if(target < nums[i]) return -1;
            }
            return -1;
        }

        return 0;
    }
}
```