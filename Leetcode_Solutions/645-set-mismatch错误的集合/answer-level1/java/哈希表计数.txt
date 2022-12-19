```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] map = new int[n + 1];
        for (int num : nums) {
            map[num]++;
        }
        int[] res = new int[2];
        for (int i = 1; i < map.length; i++) {
            if (map[i] == 0) {
                res[1] = i;
            } else if (map[i] > 1) {
                res[0] = i;
            }
        }
        return res;
    }
}
```
