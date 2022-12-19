### 解题思路
hashmap 记录需要回溯的索引

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> map = new HashMap<>() ;
        int ret = 0 ;
        int start =0 ;
        for (int i=0 ;i < s.length() ;i++) {
            if (map.containsKey(s.charAt(i))) {
                int backIndex = map.get(s.charAt(i)) ;
                while (start < s.length() && start <= backIndex){
                    map.remove(s.charAt(start)) ;
                    start ++ ;
                }
            }
            map.put(s.charAt(i),i) ;
            ret = Math.max(ret,map.size()) ;
        }
        return ret ;
    }
}
```