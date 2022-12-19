### 解题思路

### 代码

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        //各个需要的字符，而不是子串
        HashMap<Character, Integer> hashmap = new HashMap<>();

        char[] rc = ransomNote.toCharArray();
        char[] mc = magazine.toCharArray();

        for(int i = 0; i < mc.length; i++){
            if(!hashmap.containsKey(mc[i]))
                hashmap.put(mc[i], 1);
            else
                hashmap.put(mc[i], hashmap.get(mc[i])+1);
        }

        for(int i = 0; i < rc.length; i++){
            if(hashmap.containsKey(rc[i])){
                if(hashmap.put(rc[i], hashmap.get(rc[i])) == 0)
                    return false;
                hashmap.put(rc[i], hashmap.get(rc[i])-1);
            }
            else
                return false;
        }
        return true;
    }
}
```