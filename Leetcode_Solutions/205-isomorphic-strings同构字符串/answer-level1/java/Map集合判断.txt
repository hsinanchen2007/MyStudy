### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
 public boolean isIsomorphic(String s, String t) {
        char[] cs = s.toCharArray();
        char[] ct = t.toCharArray();
        if (cs.length != ct.length){
            return false;
        }
        Map<Character,Character> map = new HashMap<>();
        for (int i = 0; i < cs.length; i++) {
            if (!map.containsKey(cs[i])){
                if (map.containsValue(ct[i])){
                    return false;
                }
                map.put(cs[i],ct[i]);
            }
            else {
                if (!map.get(cs[i]).equals(ct[i])){
                    return false;
                }
            }
        }
        return true;
    }
}
```