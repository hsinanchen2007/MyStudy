### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int minimumLengthEncoding(String[] words) {

        if(words.length==1) {
            return words[0].length()+1;
        }
        for (int i = 0; i < words.length; i++) {
            String reverseWord=new StringBuilder(words[i]).reverse().toString();
            words[i]=reverseWord;
        }
        Arrays.sort(words);
        int ans=words[0].length()+1;
        for (int i = 1; i < words.length; i++) {
            if(words[i].startsWith(words[i-1])){
                ans-=words[i-1].length();
                ans+=words[i].length();
            }else {
                ans+=words[i].length()+1;
            }
        }
        return ans;
    }
}
```