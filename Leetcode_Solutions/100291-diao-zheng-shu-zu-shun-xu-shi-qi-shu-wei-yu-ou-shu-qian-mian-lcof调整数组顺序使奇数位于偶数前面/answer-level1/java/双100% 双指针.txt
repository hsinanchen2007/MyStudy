### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int left=0,right=nums.length-1;
        while (left<right){
            while (left<nums.length &&(nums[left]&1)==1)
                left++;
            while (right>=0 && (nums[right]&1)==0)
                right--;
            if (left>=right)
                break;
            int mid=nums[left];
            nums[left]=nums[right];
            nums[right]=mid;
        }
        return nums;
    }
}
```