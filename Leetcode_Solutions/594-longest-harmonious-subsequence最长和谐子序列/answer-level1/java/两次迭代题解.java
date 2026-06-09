### 解题思路
采用两次迭代题解，首先第一次迭代整个数组，并使用`TreeMap`记录下每个数组对应值出现次数（并且`TreeMap`自动进行排序）。随后对`TreeMap`进行第二次迭代，用于统计最大和谐数组的长度，首先确保当前值，有对应的和谐最大值，如果有则进行统计相加，如果没有进行下一个数值的统计，最后保存一个最大值`max`，即最大和谐数组的长度。

### 代码

```java
class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> sort = new TreeMap<>();
        for (int num : nums) {
            if (sort.get(num) != null) {
                sort.put(num, sort.get(num) + 1);
            } else {
                sort.put(num, 1);
            }
        }

        Set<Integer> keys = sort.keySet();
        int max = 0;
        for (Integer key : keys) {
            if (keys.contains(key + 1)) {
                int compare = sort.get(key) + sort.get(key + 1);
                if (compare > max) {
                    max = compare;
                }
            } else {
                continue;
            }
        }

        return max;
    }
}
```