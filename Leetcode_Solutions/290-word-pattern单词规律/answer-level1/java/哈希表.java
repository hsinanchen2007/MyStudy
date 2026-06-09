想法就是用Hash表存映射、再出现就去比对，需要注意的地方是只能一对一，那再加个Set去重Value。
```
public boolean wordPattern(String pattern, String str) {
        if (pattern == null || str == null || str.length() == 0) return false;
        String[] strings = str.split(" ");
        if (pattern.length() != strings.length) return false;
        HashMap<String, Character> map = new HashMap<>();
        HashSet<Character> sets = new HashSet<>();
        for (int i = 'a'; i < 'z' + 1; i++) {
            sets.add((char) i);
        }
        for (int i = 0; i < pattern.length(); i++) {
            if (!map.containsKey(strings[i]) && sets.contains(pattern.charAt(i))){
                map.put(strings[i],pattern.charAt(i));
                sets.remove(pattern.charAt(i));
            }else {
                if (map.get(strings[i]) == null || !map.get(strings[i]).equals(pattern.charAt(i))) {
                    return false;
                }
            }
        }
        return true;
```
![图片.png](https://pic.leetcode-cn.com/aff1406edcabfbda528dac12b8d137f0a90bb5b70f57c3a377133d4738c371ea-%E5%9B%BE%E7%89%87.png)
