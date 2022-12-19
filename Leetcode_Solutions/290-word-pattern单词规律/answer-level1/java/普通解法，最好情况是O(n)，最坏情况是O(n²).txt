### 解题思路


### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
        if(pattern == null || str == null) {
            return false;
        }
        
        String[] words = str.split(" ");
        if(words.length != pattern.length()) {
            return false;
        }
        
        int count = 0;
        int[] chars = new int[100];  //记录pattern的不同字符
        Map<Character,Integer> map = new HashMap<>();
        for(int i=0; i<pattern.length(); i++) {
            char c = pattern.charAt(i);   
            if(map.get(c) == null) {
                map.put(c,i);
                chars[count++] = i;
            } else {
                int oldIndex = map.get(c);
                if(!words[oldIndex].equals(words[i])) {  //和上次记录的比看是否一样
                    return false;
                }
            }
        }
        
        //最坏情况，排除"abba""dog dog dog dog"的情况
        for(int i=0; i<count; i++) {
            for(int j=i+1; j<count; j++) {
                if(words[chars[i]].equals(words[chars[j]])) {
                    return false;
                }
            }
        }
        return true;
    }

    
}
```