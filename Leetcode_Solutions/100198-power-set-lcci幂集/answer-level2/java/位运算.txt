# 思路
nums = [1, 2, 3]，长度为3，取看成是1，不取看成是0.
那么就有：
[0, 0, 0] -> 0
[0, 0, 1] -> 1
[0, 1, 0] -> 2
[0, 1, 1] -> 3
[1, 0, 0] -> 4
[1, 0, 1] -> 5
[1, 1, 0] -> 6
[1, 1, 1] -> 7

把这些0和1看成是二进制，代表0~7共8个数字。幂集个数是2^nums.length个。

# 代码
```java
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        int len = nums.length, total = 1 << len;
        for (int i = 0; i < total; ++i) {
            LinkedList<Integer> list = new LinkedList<>();
            int num = i, idx = 0;
            while (num != 0) {
                if ((num & 1) != 0)
                    list.addLast(nums[idx]);
                num >>= 1;
                ++idx;
            }
            res.add(list);
        }
        return res;
    }
}
```
