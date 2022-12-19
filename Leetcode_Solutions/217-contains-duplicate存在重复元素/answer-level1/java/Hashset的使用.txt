### 解题思路
* 使用add方法而不是contains方法,简化操作

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> hSet = new HashSet<>();
        for (Integer num : nums) {
            if (!hSet.add(num)) {
                return true;
            } 
        }
        return false;
    }
}
```