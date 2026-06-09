### 解题思路
用HashMap保存数字个数，key是数字，value是数字的个数，然后对value进行由大到小排序，然后让总个数循环减去最大的数字的个数直到小于一半为止

### 代码

```java
class Solution {
    public int minSetSize(int[] arr) {
        if (arr.length == 0) return 0;
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (m.containsKey(arr[i])) {
                int value = m.get(arr[i]);
                m.put(arr[i], value + 1);
            } else {
                m.put(arr[i], 1);
            }
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(m.entrySet());
        Collections.sort(list, (a, b) -> b.getValue() - a.getValue());
        int half = arr.length / 2;
        int now = arr.length;
        int res = 0;
        for (Map.Entry s : list)
        {
            if (now <= half) break;
            now -= (int)s.getValue();
            res++;
        }
        return res;
    }
}
```