### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   Map<String, List<String>> map = new HashMap<>();
    List<List<String>> result = new ArrayList<>();

    public List<List<String>> groupAnagrams(String[] strs) {
        for (int i = 0; i < strs.length; i++) {
            String string = strs[i];
            char[] chars = string.toCharArray();
            Arrays.sort(chars);
            String string2 = String.valueOf(chars);
            if (map.get(string2) != null) {
                map.get(string2).add(string);
            } else {
                List<String> list = new ArrayList<>();
                list.add(string);
                map.put(string2, list);
            }
        }

        for (Map.Entry entry : map.entrySet()) {
           result.add((List<String>) entry.getValue()); 
        }
        return result;
    }
}
```