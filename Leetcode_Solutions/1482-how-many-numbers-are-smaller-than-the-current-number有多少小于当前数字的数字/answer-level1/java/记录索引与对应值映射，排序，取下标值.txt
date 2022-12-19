### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] result = new int[nums.length];
        Map<Integer, Integer> map = new HashMap<>();
        int i = 0;
        for (int x : nums) {
            map.put(i++, x);
        }
        List<Integer> list = Arrays.stream(nums).boxed().sorted().collect(Collectors.toList());
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int cnt = list.indexOf(entry.getValue());
            result[entry.getKey()] = cnt;
        }
        return result;
    }
}
```