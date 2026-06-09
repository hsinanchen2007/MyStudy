### 解题思路
从数组的两端开时比较，左侧大于右侧时，左侧元素向右移一位，右侧元素大于左侧时，右侧元素向左移一位
。
### 代码

```java
class Solution {
    public int findMin(int[] nums) {
        int l=0;
        int r=nums.length-1;
        while(l<r){
          if(nums[l]>nums[r]){
            l++;
          }else{
            r--;
          }
        }
        return nums[l];
    }
}
```