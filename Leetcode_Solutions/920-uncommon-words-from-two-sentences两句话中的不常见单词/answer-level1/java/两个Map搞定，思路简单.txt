### 解题思路
1.将两个字符串拆成单词放入Map中
2.分辨遍历两个Map，如果value值等于1，切在另一个map中不存在的满足条件加入结果list
3.结果list转String数组。

**注意空字符串的情况，不要加入map。**

### 代码

```java
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String, Integer> mapA = new HashMap<>();
        Map<String, Integer> mapB = new HashMap<>();
        String[] stringsA = A.split(" ");
        for (String s : stringsA) {
            if (s.isEmpty()) {
                continue;
            }
            mapA.put(s, mapA.getOrDefault(s, 0) + 1);
        }
        String[] stringsB = B.split(" ");
        for (String s : stringsB) {
            if (s.isEmpty()) {
                continue;
            }
            mapB.put(s, mapB.getOrDefault(s, 0) + 1);
        }
        List<String> results = new ArrayList<>();
        for (Map.Entry entry : mapA.entrySet()) {
            if (!mapB.containsKey(entry.getKey()) && (int) entry.getValue() < 2) {
                results.add((String) entry.getKey());
            }
        }

        for (Map.Entry entry : mapB.entrySet()) {
            if (!mapA.containsKey(entry.getKey()) && (int) entry.getValue() < 2) {
                results.add((String) entry.getKey());
            }
        }

        String[] realResults = new String[results.size()];
        for (int i = 0; i < realResults.length; i++) {
            realResults[i] = results.get(i);
        }
        return realResults;
    }
}
```