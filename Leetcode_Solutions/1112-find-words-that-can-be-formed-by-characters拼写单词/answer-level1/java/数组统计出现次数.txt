### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] chars_count = new int[26];
        for(int i=0;i<chars.length();i++){
            chars_count[chars.charAt(i)-'a']++;
        }
        int res = 0;
        for(String s:words){
            int flag= 0;
            int[] s_count = new int[26];
            for(int i=0;i<s.length();i++)
                s_count[s.charAt(i)-'a']++;
            for(int i=0;i<26;i++){
                if(s_count[i]>chars_count[i]){
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                res += s.length();
        }
        return res;
    }
}
```