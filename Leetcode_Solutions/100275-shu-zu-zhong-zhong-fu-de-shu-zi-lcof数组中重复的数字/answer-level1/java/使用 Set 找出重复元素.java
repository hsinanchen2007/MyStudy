### 解题思路
利用 Set 集合不可重复，将数组一个个加入到 Set 集合，加入后判断返回的值，如果为 false 说明存在相同值，即返回该值。

### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        for (int num : nums){
            boolean add = set.add(num);
            if(!add){
                return num;
            }
        }
        return -1;
    }
}
```