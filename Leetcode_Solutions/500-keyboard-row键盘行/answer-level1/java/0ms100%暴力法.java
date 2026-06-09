### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String[] findWords(String[] words) {
        String s1="qwertyuiopQWERTYUIOP";
        String s2="asdfghjklASDFGHJKL";
        String s3="zxcvbnmZXCVBNM";
        List<String> list=new ArrayList<>();
        for (String word:words){
            if (s1.contains(String.valueOf(word.charAt(0)))){
                boolean yes=true;
                for (int i=1;i<word.length();i++){
                    if (!s1.contains(String.valueOf(word.charAt(i)))) {
                        yes=false;
                        break;
                    }
                }
                if (yes)
                    list.add(word);
            }
            else if (s2.contains(String.valueOf(word.charAt(0)))){
                boolean yes=true;
                for (int i=1;i<word.length();i++){
                    if (!s2.contains(String.valueOf(word.charAt(i)))) {
                        yes=false;
                        break;
                    }
                }
                if (yes)
                    list.add(word);
            }
            else{
                boolean yes=true;
                for (int i=1;i<word.length();i++){
                    if (!s3.contains(String.valueOf(word.charAt(i)))) {
                        yes=false;
                        break;
                    }
                }
                if (yes)
                    list.add(word);
            }
        }
        return list.toArray(new String[0]);
    }
}
```