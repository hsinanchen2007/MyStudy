### 解题思路
contains()判断是多此一举
### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet set = new HashSet();
        for(int num : nums){
            if(!set.add(num)){
                return true;
            }
        }
        return false;
    }
}
```