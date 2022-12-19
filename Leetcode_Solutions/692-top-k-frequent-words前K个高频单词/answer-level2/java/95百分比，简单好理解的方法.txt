### 解题思路
直接map对value和key排序，获取前K个即可。
简单暴力，超过95百分比

### 代码

```java
class Solution {
    Map<String, Integer> map = new HashMap<>();

    public List<String> topKFrequent(String[] words, int k) {
        //统计词频
        for (String string : words) {
            map.put(string, map.getOrDefault(string, 0) + 1);
        }

        List<Map.Entry> tmps = new ArrayList<>();
        for (Map.Entry entry : map.entrySet()) {
            tmps.add(entry);
        }
        Collections.sort(tmps, new Comparator<Map.Entry>() {
            @Override
            public int compare(Map.Entry entry1, Map.Entry entry2) {
                //value 相同按字母排序
                if (entry1.getValue() == entry2.getValue()) {
                    return ((String) entry1.getKey()).compareTo((String) entry2.getKey());
                }
                //按value排序
                return (int) entry2.getValue() - (int) entry1.getValue();
            }
        });
        //获取结果
        List<String> results = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            results.add((String) tmps.get(i).getKey());
        }
        return results;
    }
}
```