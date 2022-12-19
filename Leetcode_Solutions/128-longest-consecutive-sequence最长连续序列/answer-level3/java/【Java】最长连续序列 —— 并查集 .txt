`findParent`方法寻找父节点，并将父节点保存下来；`merge`方法合并两个节点，更新父节点和计数。
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int ans = 1;
        for (int num : nums) {
            parent.put(num, num);
            count.put(num, 1);
        }
        for (int num : nums) {
            if (count.containsKey(num + 1)) {
                ans = Math.max(ans, merge(num, num + 1));
            }
        }
        return ans;
    }
    Map<Integer, Integer> parent = new HashMap<>();
    Map<Integer, Integer> count = new HashMap<>();
    int findParent(int i) {
        if (i == parent.get(i)) {
            return i;
        }
        int ret = findParent(parent.get(i));
        parent.put(i, ret);
        return ret;
    }
    int merge(int x, int y) {
        x = findParent(x);
        y = findParent(y);
        if (x == y) {
            return count.get(x);
        }
        count.put(x, count.get(x) + count.get(y));
        parent.put(y, x);
        return count.get(x);
    }
}
```
