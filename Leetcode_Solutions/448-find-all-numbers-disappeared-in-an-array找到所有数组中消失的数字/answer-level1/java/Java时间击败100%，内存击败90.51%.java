
![屏幕快照 2020-01-11 17.46.11.png](https://pic.leetcode-cn.com/102bad5cf3bf42f18836f5435de79ebc7d9be954f92dc4d4f24ae6eecf888240-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-11%2017.46.11.png)

```
    class Solution {
        public List<Integer> findDisappearedNumbers(int[] nums) {
            List<Integer> list = new ArrayList<>(nums.length);
            int[] result = new int[nums.length];
            for (int i = 0; i < nums.length; i++) {
                result[nums[i] - 1] = 1;
            }
            for (int i = 0; i < result.length; i++) {
                if (result[i] == 0) {
                    list.add(i + 1);
                }
            }
            return list;
        }
    }
```
