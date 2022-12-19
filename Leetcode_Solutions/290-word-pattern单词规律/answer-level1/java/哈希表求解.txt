
建立字符串和字符的映射关系，存入hashmap的dict
如果字符串和字符都没存在于dict，那么就把这一对放入dict
如果字符串不存在dict，而它对应的字符已经存在了，说明有其他字符串对应到，不符合规律
如果字符串存在于dict，那么就去找到它的字符，和目前pattern中的字符比较是否相同

```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        HashMap<String, Character> dict = new HashMap<>();
        
        String[] ss = str.split(" ");
        
        if(pattern.length() != ss.length) {
            return false;
        }
        
        for(int i = 0; i < ss.length; ++ i) {
            if(! dict.containsKey(ss[i]) && dict.containsValue(pattern.charAt(i))) {
                
                return false;
                
            } else if(! dict.containsKey(ss[i]) && !dict.containsValue(pattern.charAt(i))) {
                dict.put(ss[i], pattern.charAt(i));
            } else {
                
                char ch = pattern.charAt(i);
                char v = dict.get(ss[i]);
                if(ch != v) {
                    return false;
                }
                
            }
        }
        
        return true;
    }
}
```
