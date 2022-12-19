```java
class Solution {
    public boolean canReorderDoubled(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>(nums.length);
        int zeroNum = 0;
        for (int num : nums) {
            if (num == 0) {
                zeroNum++;
                continue;
            }
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        if (zeroNum % 2 != 0) {
            return false;
        }
        Arrays.sort(nums);
        for (int num : nums) {
            if (map.containsKey(num) && num % 2 == 0) {
                int half = num / 2;
                int n = map.getOrDefault(num, 0);
                int h = map.getOrDefault(half, 0);
                if (n > h) {
                    map.put(num, n - h);
                    map.remove(half);
                } else if (n < h) {
                    map.remove(num);
                    map.put(half, h - n);
                } else {
                    map.remove(half);
                    map.remove(num);
                }
            }
        }
        return map.size() == 0;
    }

}
```
