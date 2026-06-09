### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> counts = new HashMap<>(128);
        //用一个map存储每个元素出现的次数
        for (int i = 0; i <= nums.length - 1; i++) {
            Integer oriCount = counts.get(nums[i]) == null ? 0 : counts.get(nums[i]);
            counts.put(nums[i], oriCount + 1);
        }
        //找到map中最大的value对应的key
        Integer max = 0;
        Integer targetKey = 0;
        for (Integer key : counts.keySet()) {
            if (counts.get(key) > max) {
                max = counts.get(key);
                targetKey = key;
            }
        }
        return targetKey;
    }
}

```