### 解题思路
简单粗暴

### 代码

```java
class Solution {
    public int missingNumber(int[] nums) {
        int i=0;
        int j=nums.length;
        for(i=0;i<j;i++){
            if(nums[i] != i){
                return i;
            }
        }
        return nums[i-1] + 1;
    }
}
```