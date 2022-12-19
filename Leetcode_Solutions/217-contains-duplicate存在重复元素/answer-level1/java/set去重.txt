### 解题思路
set去重法

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        //set法
        Set<Integer> set = new HashSet();
        
        //bad-case
        if (nums.length < 2) {
            return false;
        }

        for (int i = 0; i < nums.length; i ++) {
            if (set.contains(nums[i])) {
                return true;
            } else {
                set.add(nums[i]);
            }
        }

        return false;
    }
}
```