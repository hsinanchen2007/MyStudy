 一次遍历，如果map存在当前字符，则移除indexs中的当前下标，否则往indexs中插入当前下标
 最后如果indexs为空，说明不存在第一个唯一字符，返回-1，否则返回第一个元素
```
public int firstUniqChar(String s) {
        
        if (s == null || s.length() == 0) {
            return -1;
        }
        List<Integer> indexs = new ArrayList<>(s.length());
        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                indexs.remove(map.get(s.charAt(i)));
            } else {
                indexs.add(i);
            }
            map.put(s.charAt(i), i);
        }
        return indexs.size() == 0 ? -1 : indexs.get(0);
    }
```
