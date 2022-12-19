### 解题思路
1、哈希统计数字频次
2、新建一个TreeMAP，对key倒序排列
3、直接遍历TreeMap输出结果

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> frequent = new HashMap<>();
        for (int i : nums) frequent.put(i, frequent.getOrDefault(i, 0) + 1);
        // key-value倒置，并对key倒序排
        Map<Integer, List<Integer>> treeMap = new TreeMap<>(Comparator.comparing(Integer::intValue).reversed());
        for (Map.Entry<Integer, Integer> entry : frequent.entrySet()) {
            List<Integer> valueList = treeMap.getOrDefault(entry.getValue(), new ArrayList<>());
            if (!valueList.contains(entry.getKey())) valueList.add(entry.getKey());
            treeMap.put(entry.getValue(), valueList);
        }
        // 顺序输出结果
        List<Integer> data = new ArrayList<>();
        for (Map.Entry<Integer, List<Integer>> entry : treeMap.entrySet()) {
            if (data.size() < k) data.addAll(entry.getValue());
        }
        return data;
    }
}
```