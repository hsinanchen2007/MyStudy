### 结果
执行用时 :
890 ms
, 在所有 Java 提交中击败了
5.00%
的用户
内存消耗 :
39.9 MB
, 在所有 Java 提交中击败了
22.16%
的用户

### 解题思路
想法就是将出现的可能的四个数字的组合全找出来，找的过程中要过滤掉一些重复项。我的代码中有一个地方是造成了性能不好的主要原因，给的数字中会有重复的情况，我在排列的过程中是将每一个元素当成了独立的存在(即以他们出现的位置为标识而不是以他们的值)，因此结果会出现一些相同，为了过滤掉这些相同又不得不加进了一个hashmap进行判断。

### 代码

```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    List<List<Integer>> rst = new ArrayList<>();
    int goal;
    Map<String, Boolean> cache = new HashMap<>();

    public List<List<Integer>> fourSum(int[] nums, int target) {
        if (nums.length < 4) return rst;
        goal = target;
        Arrays.sort(nums);
        boolean[] flag = new boolean[nums.length];
        findFourNum(nums, flag, 0, 0, 0);
        return rst;
    }

    private void findFourNum(int[] nums, boolean[] flag, int sum, int time, int pos) {
        if (time > 4) {
            return;
        }
        if (goal >= 0 && sum > goal) {
            return;
        }
        if (time == 4 && sum != goal) {
            return;
        }

        if (time == 4 && sum == goal) {
            String key = "";
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < flag.length; i++) {
                if (!flag[i]) continue;
                key = key + nums[i];
                list.add(nums[i]);
            }
            if (cache.get(key) == null) {
                rst.add(list);
                cache.put(key, true);
            }
            return;
        }
        
        // 类似于全排列，将出现的所有数字进行可能的所有排列
        for (int i = pos; i < nums.length; i++) {
            flag[i] = true;
            findFourNum(nums, flag, sum + nums[i], time + 1, i + 1);
            flag[i] = false;
        }
    }
}
```