### 解题思路
此处撰写解题思路
hashmap小题大做了。。
执行用时 :
10 ms
, 在所有 Java 提交中击败了
6.45%
的用户
内存消耗 :
42.3 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int len = nums.length;
        int res = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int  num : nums){
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        if (map.containsKey(target))res = map.get(target);
        return res;
    }
}
```