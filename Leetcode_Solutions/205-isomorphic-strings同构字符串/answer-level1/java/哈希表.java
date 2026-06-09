### 解题思路
这一题使用了java中的哈希表。
判断key-value是否匹配。
然后还需要判断value值是否对应同一个key。

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length() != t.length())
            return false;
        
        HashMap<Character, Character> hashmap = new HashMap<>();
        for(int i = 0; i < s.length(); i++){
            char key = s.charAt(i);
            char value = t.charAt(i);
            Set<Character> keyset = hashmap.keySet();
            
            for(char key2 : keyset){
                char value2 = hashmap.get(key2);
                if(value2 == value && key != key2)
                    return false;
            }

            if(!hashmap.containsKey(key)){
                hashmap.put(key, value);
            }
            else{
                if(value != hashmap.get(key))
                    return false;
            }
        }
        return true;
    }
}
```