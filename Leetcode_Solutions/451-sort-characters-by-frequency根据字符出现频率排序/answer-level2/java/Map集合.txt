### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public String frequencySort(String s) {
        char[] chars = s.toCharArray();
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < chars.length; i++) {
            if (map.containsKey(chars[i])) { //
                map.put(chars[i], map.get(chars[i]) + 1);
            } else {
                map.put(chars[i], 1);
            } 
        }
        StringBuilder res = new StringBuilder();//
        List<Map.Entry<Character,Integer>> list = new ArrayList<>(map.entrySet());//
        list.sort(((o1, o2) -> o2.getValue() - o1.getValue()));
        for (Map.Entry<Character,Integer> var:list) { // 
            for (int i = 0; i < var.getValue(); i++) {
                res.append(var.getKey());
            }
        }
        return res.toString();
    }
}
```