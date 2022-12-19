### 解题思路
使用HashMap存入s对应的t的对应关系。同时，每加入一个对应关系，想用的t就不能再重复了，所以增加一个HashSet来应对重复的问题。

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> map = new HashMap(); // s->t 的HashMap
        HashSet<Character> usedT = new HashSet(); // 用过的t，不能再用了
        for (int i = 0; i < s.length(); i++){
            char s_char = s.charAt(i);
            char t_char = t.charAt(i);
            if (map.containsKey(s_char)){
                // 如果存在就比较当前的s是否对应的是正确的t
                if (map.get(s_char) != t_char){
                    return false;
                }
            } else {
                // 检查t是否用过
                if (usedT.contains(t_char)){
                    return false;
                }
                // 新增当前的s对应当前的t的规则，同时告诉程序当前的t已经用了
                map.put(s_char, t_char);
                usedT.add(t_char);
            }
        }
        return true;
    }
}
```