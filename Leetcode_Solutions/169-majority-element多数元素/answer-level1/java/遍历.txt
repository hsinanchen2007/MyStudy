### 解题思路
从第二个数开始，遇到相同的就加1，遇到不同的就减去1

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count=1, temp = nums[0];
        for (int i=1; i<nums.length; i++) {
            if (nums[i] == temp) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    // 注意这里，数组的索引是可以取i+1的，不会越界
                    temp = nums[i+1];
                }
            }
        }
        return temp;

    }
}
```