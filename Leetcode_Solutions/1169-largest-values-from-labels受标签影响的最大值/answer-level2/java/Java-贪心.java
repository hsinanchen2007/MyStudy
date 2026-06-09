# 思路
`items[i][0]`存`value`，`items[i][1]`存`label`。
根据`value`**降序排序**，每次取当前最大的`value`，若能添加到最终结果中则添加。

# 代码(HashMap)
```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        int len = values.length;
        int[][] items = new int[len][2];
        for (int i = 0; i < len; ++i) {
            items[i][0] = values[i];
            items[i][1] = labels[i];
        }
        Arrays.sort(items, Comparator.comparingInt(i -> -i[0]));
        HashMap<Integer, Integer> map = new HashMap<>();
        int res = 0;
        for (int[] item : items) {
            int label_count = map.getOrDefault(item[1], 0);
            if (label_count < use_limit) {
                res += item[0];
                if (--num_wanted == 0)
                    break;
                map.put(item[1], label_count + 1);
            }
        }
        return res;
    }
}
```

# 代码(数组)
既然题目说了`label`的值的范围是`[0, 20000]`，那就将`HashMap`改为数组，速度更快。
```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        int len = values.length;
        int[][] items = new int[len][2];
        for (int i = 0; i < len; ++i) {
            items[i][0] = values[i];
            items[i][1] = labels[i];
        }
        Arrays.sort(items, Comparator.comparingInt(i -> -i[0]));
        int[] label_count = new int[20001];
        int res = 0;
        for (int[] item : items) {
            int count = label_count[item[1]];
            if (count < use_limit) {
                res += item[0];
                if (--num_wanted == 0)
                    break;
                ++label_count[item[1]];
            }
        }
        return res;
    }
}
```
