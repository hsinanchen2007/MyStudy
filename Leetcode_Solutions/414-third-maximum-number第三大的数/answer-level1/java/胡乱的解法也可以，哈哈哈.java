### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int thirdMax(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }
        int[] sums = new int[set.size()];
        int i = 0;
        for (int value : set) {
            sums[i++] = value;
        }
        Arrays.sort(sums);
        if (sums.length < 3) {
            return sums[sums.length - 1];
        }
        return sums[sums.length - 3];
    }
}
```