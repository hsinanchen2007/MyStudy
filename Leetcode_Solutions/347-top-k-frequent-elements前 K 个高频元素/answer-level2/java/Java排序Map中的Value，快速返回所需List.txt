### 解题思路
首先将nums中的值都放入map中，其次根据map中value的值对map进行降序排列，最后取出前k个最大值

### 代码

```java
class Solution {
    public static List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int num = map.getOrDefault(nums[i], 0);
            map.put(nums[i], ++num);
        }

        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() { //根据map中value的值对map进行降序排列
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                int compare = (o1.getValue()).compareTo(o2.getValue());
                return -compare;
            }
        });

        int i = 0; //取出前k个最大值
        for (Map.Entry<Integer, Integer> entry : list) {
            res.add(entry.getKey());
            if (++i == k) break;
        }
        return res;
    }
}
```