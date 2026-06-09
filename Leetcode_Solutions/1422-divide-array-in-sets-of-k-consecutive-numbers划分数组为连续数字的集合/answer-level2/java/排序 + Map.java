    思路上很清晰，先将数组排序，再把每个数字以及它们对应出现的次数存进map里面；
    接着遍历数组，每遇到一个num，就把num, num + 1, ... num + k - 1这k个数结合map，按序进行判断;
    若存在且对应的value值大于0，则value值减1，否则直接return false。

```
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0)
            return false;
        if (k == 1)
            return true;
        Arrays.sort(nums);
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums)
            map.put(num, map.getOrDefault(num, 0) + 1);
        for (int num : nums) {
            if (map.get(num) != 0) {
                int start = num;
                int end = num + k - 1;
                while (start <= end) {
                    Integer v = map.get(start);
                    if (v != null && v > 0)
                        map.put(start++, v - 1);
                    else
                        return false;
                }
            }
        }
        return true;
    }
}
```
