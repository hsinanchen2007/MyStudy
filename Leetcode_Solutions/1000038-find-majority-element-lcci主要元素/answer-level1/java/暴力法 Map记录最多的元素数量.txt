```
class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        if (nums.length == 1) {
            return nums[0];
        }
        for (int i = 0; i < nums.length; i++) {
            Integer num = nums[i];
            if (map.containsKey(num)) {
                int tmp = map.get(num) + 1;
                if (tmp > len / 2) {
                    return num;
                } else {
                    map.put(num, tmp);
                }
            } else {
                map.put(num, 1);
            }
        }
        return -1;
    }
}
```
