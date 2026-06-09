使用hash表统计，s字符串+1,t字符串-1,如果是0则remove，最后判断map的size，如>0则说明不同。
 ```
public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.get(s.charAt(i)) == null ? 1 : (map.get(s.charAt(i)) + 1));
            map.put(t.charAt(i), map.get(t.charAt(i)) == null ? -1 : (map.get(t.charAt(i)) - 1));
            if (map.get(s.charAt(i)) != null && map.get(s.charAt(i)) == 0)
                map.remove(s.charAt(i));
            if (map.get(t.charAt(i)) != null && map.get(t.charAt(i)) == 0)
                map.remove(t.charAt(i));
        }
        if (map.size() == 0) return true;
        return false;
    }
```
