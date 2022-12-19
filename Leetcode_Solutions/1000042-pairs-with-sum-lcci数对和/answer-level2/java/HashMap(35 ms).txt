![微信图片_20200221001143.png](https://pic.leetcode-cn.com/03aa04f5b7d7ff141dc2e4dd9f3b82bd4f00987c115e156a41576a86d6dbee83-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200221001143.png)

# 代码
```java
class Solution {
    public List<List<Integer>> pairSums(int[] nums, int target) {
        List<List<Integer>> res = new LinkedList<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums)
            map.merge(num, 1, (old_val, new_val) -> old_val + new_val);
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int val = entry.getKey();
            if (val > target) continue;
            int num = entry.getValue();
            if (num > 0) {
                if ((val << 1) == target) {
                    int pair = num >> 1;
                    if (pair > 0) {
                        num %= 2;
                        while (--pair > -1)
                            res.add(Arrays.asList(val, val));
                        map.put(val, num);
                    }
                    continue;
                }
                int fit_num;
                if ((fit_num = map.getOrDefault(target - val, 0)) > 0) {
                    int limit = Math.min(num, fit_num);
                    num -= limit;
                    fit_num -= limit;
                    while (--limit > -1)
                        res.add(Arrays.asList(val, target - val));
                    map.put(val, num);
                    map.put(target - val, fit_num);
                }
            }
        }
        return res;
    }
}
```
