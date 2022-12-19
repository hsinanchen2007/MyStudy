### 解题思路
利用数组做两次hashmap，即可，时间复杂度O(n)

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()) return false;
        int[] maps = new int[128];
        int[] mapt = new int[128];
        for(int i=0;i<s.length();++i){
            char cs = s.charAt(i);
            char ct = t.charAt(i);
            if(maps[cs]==ct&&mapt[ct]==cs) continue;
            if(maps[cs]==0&&mapt[ct]==0){
                maps[cs]=ct;
                mapt[ct]=cs;
            }
            else{
                return false;
            }
        }
        return true;
    }
}
```