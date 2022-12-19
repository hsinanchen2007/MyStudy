### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int num = nums[0];
        int count = 1;

        for(int i = 1; i < nums.length; i++){
            if(num == nums[i]) {
                count++;
            } else {
                if(count == 0) {
                    num = nums[i];
                    count = 1;
                } else {
                    count--;
                }
            }
        }

        return num;
    }
}
```