### 解题思路
套用二分模板 
首先考虑怎么去寻找首个和末尾个
寻找首个 当找到这个数并且前面一个数 不相等就是
末尾个  当找到这个数并且后面一个数 不相等就是
边界问题 
当只有一个数的时候 寻找首个不能超过 0 寻找末尾 不能超过 nums.length-1
储存问题 
用一个数做标记 当这个数为0时寻找首个 为1时寻找末尾个 

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int end = nums.length-1;
        int start = 0;
        int mid = (start+end)>>1;
        int num[] = null;
        num = new int[2];
        num [0] = -1;
        num [1] = -1;
        int i =0;
        while(start <= end){
            if((i == 0 && nums[mid] == target && ( mid == 0 || nums[mid-1] != target))||(i == 1 && nums[mid] == target && (mid == end || nums[mid+1] != target ))) {
                num[i++] = mid;
                mid = (start+end)>>1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }else if(nums[mid] < target){
                start = mid+1;
            }else if(i == 0){
                mid = mid -1;
            }else if(i == 1){
                mid = mid + 1;
            }
            if(nums[mid] != target){
                mid = (start+end)>>1;
            }
            if(i == 2)break;
        }
        return num;
    }
}
```