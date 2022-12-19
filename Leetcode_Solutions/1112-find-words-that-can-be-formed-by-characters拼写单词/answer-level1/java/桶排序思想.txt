### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if(words == null || words.length == 0 || chars.length() == 0){
            return 0;
        }
        int cnt[] = new int[26];
        int totalsize = 0;
        // for(Character c: chars.toCharArray()){
        //     cnt[c-'a']++;
        // }
        for(String s: words){
            for(Character c: chars.toCharArray()){
                cnt[c-'a']++;
            }
            for(int i = 0; i < s.length(); i++){
                if(cnt[s.charAt(i)-'a'] > 0){
                    cnt[s.charAt(i)-'a']--;
                    if(i == s.length() - 1){
                        totalsize += s.length();
                    }
                }else{
                    break;
                }
            }
            Arrays.fill(cnt, 0);
        }
        return totalsize;
    }
}
```