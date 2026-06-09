### 解题思路
此处撰写解题思路
主要是提取数组内元素，用For语句的嵌套进行一一计算
### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j <nums.length ; j++) {
                if(nums[i]+nums[j] == target ) {
                    return new int[]{i,j};
                }
            }
        }
        return null;

    }
}
```