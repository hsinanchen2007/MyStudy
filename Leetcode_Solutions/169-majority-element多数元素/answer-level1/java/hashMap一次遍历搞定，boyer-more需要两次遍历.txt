### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> numsCount = new HashMap<>();

        for (int num : nums) {
            int count = numsCount.getOrDefault(num, 0);
            count++;
            if (count > nums.length / 2) {
                return num;
            }
            numsCount.put(num, count);
        }
        return -1;

    }
}
```