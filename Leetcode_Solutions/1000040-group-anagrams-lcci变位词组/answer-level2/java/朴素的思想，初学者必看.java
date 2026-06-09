### 解题思路
1.构造一个map保存所有的变位词组 map的key是排序后的，map的value为原始值
2. 输出结果

### 代码

```java
class Solution {
    Map<String, List<String>> maps = new HashMap<>();

    public List<List<String>> groupAnagrams(String[] strs) {
        for (String string : strs) {
            String tmp = sort(string);
            maps.computeIfAbsent(tmp, x -> new ArrayList<>()).add(string);
        }
        List<List<String>> results = new ArrayList<>();
        for (Map.Entry entry : maps.entrySet()) {
            results.add((List<String>) entry.getValue());
        }
        return results;
    }

    private String sort(String string) {
        char[] chars = string.toCharArray();
        Arrays.sort(chars);
        StringBuffer stringBuffer = new StringBuffer();
        for (char ch : chars) {
            stringBuffer.append(ch);
        }
        return stringBuffer.toString();
    }
}
```