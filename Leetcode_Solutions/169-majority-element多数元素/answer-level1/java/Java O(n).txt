### 解题思路
打卡

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int num = nums[0];
        int count = 0;
        for(int el : nums){
            if(num == el) count++;
            else count--;
            if(count++ == 0) num = el;
            else count--;
        }
        return num;
    }
}
```