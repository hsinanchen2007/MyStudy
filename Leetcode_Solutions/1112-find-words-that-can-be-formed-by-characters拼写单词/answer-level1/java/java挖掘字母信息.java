** 解题思路**
单词里面的字母想要分开来去chars中找，但是找见了也不意味着符合，因为可能需要多个相同字母，于是把这个潜在信息做如下处理：分别设置两个辅助数组，即对应words里每个单词和chars里里面每个字母背后的数量信息都包含其中，若没有则为0

** 代码**

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int c[]=new int[26];
        int res=0;
        for(char ch:chars.toCharArray()){
            c[(int)(ch-'a')]+=1;//chars对应的c数组
        }
        a:for(String wrd:words){
            int w[]=new int[26];
            for(char ww:wrd.toCharArray()){
                w[(int)(ww-'a')]+=1;//里面每一个单词wrd对应的w数组
            }
            for(int i=0;i<26;i++){
                if(w[i]>c[i]){
                    continue a;
                }
            }//在res前面设置路障，只有通过的才可以res+
            res+=wrd.length();

        }
        return res;
    }
}
```