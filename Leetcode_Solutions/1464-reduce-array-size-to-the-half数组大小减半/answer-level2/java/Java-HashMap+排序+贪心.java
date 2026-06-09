# 思路
利用`HashMap`统计`arr`数组中各个**数值**出现的**次数**，其中`key = 数值`, `value = 出现次数`。
统计结束后将`HashMap`中所有`value(即出现次数)`添加到`ArrayList`中。
随后根据**出现次数**，将利用`Collections.sort()`根据`value(即出现次数)`**降序排序**。
将数组原始长度的一半记为`limit`，将数组原始长度记为`len`，用其减去**当前最大**的**出现次数**，判断`len`是否`< limit`。

# 代码
```java
class Solution {
    public int minSetSize(int[] arr) {
        int len = arr.length, res = 0, limit = len >> 1;
        HashMap<Integer, Integer> map = new HashMap<>(len);
        for (int num : arr)
            map.merge(num, 1, (o_val, n_val) -> o_val + n_val);
        ArrayList<Integer> list = new ArrayList<>(map.values());
        Collections.sort(list, Comparator.comparingInt(item -> -item));
        for (int num : list) {
            ++res;
            if ((len -= num) <= limit)
                return res;
        }
        return -1;
    }
}
```

# 代码(stream写法)
PS:对于小数据量而言，使用stream会很慢
```java
class Solution {
    public int minSetSize(int[] arr) {
        int len = arr.length, res = 0, limit = len >> 1;
        Map<Integer, Long> map = Arrays.stream(arr).boxed().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        ArrayList<Long> list = new ArrayList<>(map.values());
        Collections.sort(list, Comparator.comparingLong(item -> -item));
        for (long num : list) {
            ++res;
            if ((len -= num) <= limit)
                return res;
        }
        return -1;
    }
}
```
