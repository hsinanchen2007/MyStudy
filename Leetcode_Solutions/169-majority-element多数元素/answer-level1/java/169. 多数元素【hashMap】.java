### 解题思路
    1、使用哈希映射（HashMap）来存储每个元素以及出现的次数。对于哈希映射中的每个键值对，键表示一个元素，值表示该元素出现的次数，
    循环遍历数组 nums 并将数组中的每个元素及对应的个数加入哈希映射中；
    2、然后遍历哈希映射中的所有键值对，找出值大于 ⌊ n/2 ⌋ 的健，也就是数组对应的元素。

### 代码

```java
class Solution {
    public int majorityElement(int[] nums) {
       int len = nums.length;
        Map<Integer,Integer> ans = new HashMap<>();
        for (int i : nums) {
            ans.put(i, ans.containsKey(i)?ans.get(i)+1:1);
        }
        for (int i : nums) {
            if(ans.get(i) > len/2){
                return i;
            }
        }
        return -1;

    }
}
```