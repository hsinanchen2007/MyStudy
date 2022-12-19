### 解题思路
此处撰写解题思路
下排序在比较是否存在
### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
   Map<String,List<String>> map = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            char[] chars = strs[i].toCharArray();
            Arrays.sort(chars);
            String s = String.valueOf(chars);
            if (map.get(s) == null) {
                List<String> l = new ArrayList<>();
                l.add(strs[i]);
                map.put(s, l);
            } else {
                map.get(s).add(strs[i]);
            }
        }
        return new ArrayList<>(map.values());
    }
}
```