### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {

        List<List<String>> res = new ArrayList();
        Map<HashMap<Character,Integer>,ArrayList> map = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            HashMap<Character,Integer> ms = new HashMap<>();
            for (Character c:strs[i].toCharArray()) {
                 if (ms.containsKey(c)){
                     ms.put(c,ms.get(c)+1);
                 }
                 else {
                     ms.put(c,1);
                 }
            }
            if (!map.containsKey(ms)){
                ArrayList<String> list = new ArrayList<String>();
                list.add(strs[i]);
                map.put(ms,list);
            }
            else {
                 ArrayList<String> list  =  map.get(ms);
                 list.add(strs[i]);
                 map.put(ms,list);
            }
        }
        for (HashMap jjj:map.keySet()) {
            res.add(map.get(jjj));
        }
        return res;
    }
}
```