### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int retNum = nums[0];

        int count = 1; 
        for(int i=1; i<nums.length; i++) {
            if(nums[i] == retNum) {
                ++count;
            } else {
                --count;
            }

            if(count == 0) {
                retNum = nums[i];
                count = 1;
            }
        }

        return retNum;
    }
}
```