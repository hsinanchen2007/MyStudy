### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String sortString(String s) {
        StringBuilder sb = new StringBuilder();

        int[] charnum = new int[26];
        for(char c:s.toCharArray()){
            charnum[(int)c-97]++;
        }

        while(sb.length()!=s.length()){
            for(int i=0;i<26;i++){
                if(charnum[i]!=0){
                    charnum[i]--;
                    sb.append((char)(i+97));
                    continue;
                }
            }
            if (sb.length() == s.length())
                break;
            for(int i=25;i>=0;i--){
                if(charnum[i]!=0){
                    charnum[i]--;
                    sb.append((char)(i+97));
                    continue;
                }
            }
        }

        return sb.toString();
    }
}
```