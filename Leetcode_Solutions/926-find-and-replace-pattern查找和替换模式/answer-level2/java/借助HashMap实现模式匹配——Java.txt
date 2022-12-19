思路：遍历words，逐个匹配是否满足pattern，在匹配时，借助HashMap建立字符映射关系，条件是：每个字母映射到另一个字母中，没有两个字母映射到同一个字母。
<br/><br/>
代码：
```
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        if (words == null || words.length < 1) {
            return null;
        }
        
        List<String> ans = new ArrayList<>();
        
        for (String word : words) {
            if (judge(word,pattern)) {// 逐个匹配，满足条件就加入answer
                ans.add(word);
            }
        }
        
        return ans;
    }
    
    private boolean judge(String word,String pattern) {
        if (word.length() != pattern.length()) {
            return false;// 长度不等，直接返回false
        }
        
        Map<Character,Character> map = new HashMap<>();
        boolean ok = true;
        
        for (int i = 0;i < pattern.length();i++) {
            char key = pattern.charAt(i);
            char val = word.charAt(i);
            if (!map.containsKey(key)) {
                if (map.containsValue(val)) { // val已经有了映射关系，直接返回false
                    return false;
                }
                
                map.put(key,val);
            } else {
                if (map.get(key) != val) {// key-val已经对应，且key对应的val不等于当前的字母，所以直接返回false
                    return false;
                }
            }
        }
        
        return ok;
    }
}
```