### 解题思路
为将其中一个的字符串中的字符加入到哈希表中，然后再将另一个字符串中的字符和哈希表进行对比，然后判断是否个数相等。

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length())
            return false;
        
        HashMap<Character, Integer> hashmap = new HashMap<>();
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();

        for(int i = 0; i < sc.length; i++){
            if(!hashmap.containsKey(sc[i])){
                hashmap.put(sc[i], 1);
            }
            else{
                hashmap.put(sc[i], hashmap.get(sc[i])+1);
            }
        }

        for(int i = 0; i < tc.length; i++){
            if(!hashmap.containsKey(tc[i])){
                return false;
            }
            else{
                if(hashmap.get(tc[i]) == 0)
                    return false;
                else{
                    hashmap.put(tc[i], hashmap.get(tc[i])-1);
                }
            }
        }
        return true;
    }
}
```