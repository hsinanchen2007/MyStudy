### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        Set<Integer> set = new HashSet<>();
        List<Integer> results = new ArrayList<>();
        for (int num : nums) {
            if (set.contains(num)) {
                results.add(num);
            } else {
                set.add(num);
            }
        }
        return results;
    }
}
```