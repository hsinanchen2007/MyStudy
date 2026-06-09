### 解题思路
统计各个字母出现次数作为hashkey。

### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> groups = new HashMap<>();
        for (String str : strs) {
            int[] cntAlpha = new int[26];
            for (int i = 0; i < str.length(); i++) {
                cntAlpha[str.charAt(i) - 'a'] += 1;
            }

            String key = Arrays.toString(cntAlpha);
            if (groups.containsKey(key)){
                groups.get(key).add(str);
            }
            else{
                groups.put(key, new ArrayList<>(List.of(str)));
            }
        }
        return new ArrayList<>(groups.values());
    }
}
```