### 解题思路
首先先看两个字符串长度是否一致，然后通过hashmap记录s1每个字符出现的次数，再在s2中检测字符
1)是否在map中出现过，如果没有直接返回false
2)该字符在map中剩余次数，如果已经是0次了，也返回false
以上两个都不满足的话，就将字符在map中出现的次数减一
全部s2中的字符都走完了还没出现以上两个问题的话，就可以返回true了
### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2) {
            return false;
        }
        HashMap<Character, Integer> map = new HashMap<>();
        for(char c : s1.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        for(char c : s2.toCharArray()) {
            if(!map.containsKey(c)) {
                return false;
            } else if(map.get(c) <= 0){
                return false;
            } else {
                map.put(c, map.get(c) - 1);
            }
        }
        return true;
    }
}
```