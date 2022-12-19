### 解题思路
没有想到异或，使用的一个`set`得到所有不重复元素，把数组变为`list`。遍历`set`，删除遍历的元素，如果删除后不包含这个元素，就说明原本就只包含一个此元素，返回其值。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        List<Integer> list = Arrays.stream(nums).boxed().collect(Collectors.toList());
        HashSet<Integer> set = new HashSet(list);
        int res = 0;
        for (Integer num : set
        ) {
            list.remove(num);
            if (!list.contains(num)) {
                res = num;
            }
        }
        return res;
    }
}
```
