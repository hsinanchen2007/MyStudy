### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int low=0,high=nums.length;
        while(low<high){
            int mid=(low+high)>>1;
            if(nums[mid]!=mid) high=mid;
            else low=mid+1;
        }
        return low;
    }
}
```