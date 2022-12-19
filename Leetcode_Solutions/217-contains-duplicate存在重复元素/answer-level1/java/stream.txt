### 解题思路
直接用Stream流去重

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        return    Arrays.stream(nums).distinct().count() != nums.length;
        
    }
}
```