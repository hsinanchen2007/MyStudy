### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        Map<String, Integer> sMap = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            if(sMap.containsKey(s.substring(i, i + 1))) {
                sMap.put(s.substring(i, i + 1),sMap.get(s.substring(i, i + 1)) + 1);
            } else {
                sMap.put(s.substring(i, i + 1),1);
            }
        }
        Map<String, Integer> tMap = new HashMap<>();
        for(int i = 0; i < t.length(); i++) {
            if(tMap.containsKey(t.substring(i, i + 1))) {
                tMap.put(t.substring(i, i + 1),tMap.get(t.substring(i, i + 1)) + 1);
            } else {
                tMap.put(t.substring(i, i + 1),1);
            }
        }

        if(sMap.equals(tMap)) {
            return true;
        }

        return false;
    }
}
```