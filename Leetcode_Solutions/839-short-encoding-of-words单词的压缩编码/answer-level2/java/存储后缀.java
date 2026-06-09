### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        if(words == null || words.length == 0){
            return 0;
        }
        Set<String> set = new HashSet<>(Arrays.asList(words));
        for(String word: words){
            for(int k = 1; k < word.length(); k++){
                set.remove(word.substring(k));
            }
        }
        int ans = 0;
        for(String s: set){
            ans += s.length() + 1;
        }
        return ans;
    }
}
```