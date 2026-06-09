### 解题思路
借用treemap分组，因为要考虑重复的元素，所以不能使用treeset，但是本身这相当于在内部实现了排序，这不应该算是一个符合要求的解法

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int e : nums) {
            map.put(e, e);
        }
        Set<Integer> keys = map.keySet();
        int bid = 1;
        for(Integer i:keys){
            if(i <= 0){
                continue;
            }
            if(bid < i){
                return bid;
            }
            bid = i+1;
        }
        return bid;
    }
}
```