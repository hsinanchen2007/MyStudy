### 解题思路
先将字符串分割，再用哈希表构成单词与规律字符的映射，找准两种false的情况即可：
1）pattern:aa  word[]:dog cat  也就是说a已经与dog构成映射，但当再次出现a时对应的却是cat
2）pattern:ab  word[]:dog dog  也就是说a已经与dog构成映射，但当出现b时却对应了与原来a构成映射的dog
执行时间1ms，击败100%的用户

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] word = str.split(" ");
        if(word.length != pattern.length()) return false;
        Map<String,Character> map = new HashMap<>();
        for(int i=0;i<word.length;i++){
            if(map.containsKey(word[i])){
                if(pattern.charAt(i) != map.get(word[i])){
                    return false;
                }
            }
            else{
                if(map.containsValue(pattern.charAt(i))){
                    return false;
                }
            }
            map.put(word[i],pattern.charAt(i));
        }
        return true;
    }
}
```