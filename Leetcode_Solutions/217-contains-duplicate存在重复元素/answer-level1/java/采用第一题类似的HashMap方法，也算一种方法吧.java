### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
       HashMap<Integer,Integer> hashmap = new HashMap<>();
       int n = nums.length;
       for(int i = 0; i < n; i++){
           if(hashmap.containsKey(nums[i])) return true;
           hashmap.put(nums[i], i);
       }
       return false;
    }
}
```