通过`Map`统计每个数字出现的次数，`Map`的`key`是数字，`value`是该数字出现的次数。

遍历数组时，对数组中的每个数，从`Map`中获得次数，如果`Map`中不存在该`key`则次数为`0`，然后将次数加`1`更新到`Map`中。

然后遍历`Map`中的每个`key`值得到`value`值，将`value`值存入一个`Set`中，如果发现有重复元素则返回`false`，如果遍历结束整个`Map`没发现重复的`value`值，则返回`true`。

```
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> occurrences = new HashMap<Integer, Integer>();
        for (int num : arr) {
            int occurrence = occurrences.getOrDefault(num, 0);
            occurrence++;
            occurrences.put(num, occurrence);
        }
        Set<Integer> keySet = occurrences.keySet();
        Iterator<Integer> it = keySet.iterator();
        Set<Integer> occurrencesSet = new HashSet<Integer>();
        while (it.hasNext()) {
            int num = it.next();
            int occurrence = occurrences.get(num);
            if (!occurrencesSet.add(occurrence))
                return false;
        }
        return true;
    }
}
```
