### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        for (int i : nums) {
            if (set.contains(i)) {
                set.remove(i);
            } else {
                set.add(i);
            }
        }

        for (Integer result : set) {
            return result;
        }
        return -1;
    }
}
```