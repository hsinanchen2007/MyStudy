### 解题思路
用哈希表一个一个储存pattern中的字符，并把str转换成数组，在储存过程中判断，如果这个字符出现过，则验证这个字符对应的单词是不是跟哈希表中这个字符储存的单词一致；如果这个字符没出现过，则判断哈希表存在不存在这个字符对应的单词，存在则是错误的。
因为应该是一一对应的关系。
### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        HashMap<Character, String> match = new HashMap<>();
        String[] strs = str.split(" ");
        if(strs.length != pattern.length()) return false;
        for(int i = 0 ; i < pattern.length();i++){
            if(match.containsKey(pattern.charAt(i))){
                if(!match.get(pattern.charAt(i)).equals(strs[i])){
                    return false;
                }
            }else{
                if(match.containsValue(strs[i])) return false;
                else match.put(pattern.charAt(i),strs[i]);
            }
        }
        return true;
    }
}
```