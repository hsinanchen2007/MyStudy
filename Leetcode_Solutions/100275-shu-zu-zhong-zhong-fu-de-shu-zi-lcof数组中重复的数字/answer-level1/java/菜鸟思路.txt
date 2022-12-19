### 解题思路
利用 Set 的特性，set.add() 方法的返回值：
- 如果要假如的元素不存在，返回 true
- 如果要假如的元素已存在，返回 false

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int i : nums) {
            boolean exist = set.add(i);
            if (!exist) {
                return i;
            }
        }
        // 没有重复的
        return -1;
    }
}
```