### 解题思路
1.遍历数组用map保存每个数字出现的次数。
2.遍历map，找出value为1的key。

### 代码

```java
class Solution {
    Map<Integer, Integer> map = new HashMap<>();

    public int singleNumber(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }

        for (Map.Entry entry : map.entrySet()) {
            if ((int) entry.getValue() == 1) {
                return (int) entry.getKey();
            }
        }
        return -1;
    }
}
```