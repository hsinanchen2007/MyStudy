
首先对于每个单词，如果都能用同一张字母表保存就好了。要解决的问题是：
* 一张字母表的重复利用
* 每个字母在字母表中快速对应，并且字母表可以动态保存比对过程中剩余可使用的单词。

这里没有使用int[26],因为char换算成int还有开销，索性牺牲一部分空间直接用char的原始值作为下标。

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] table = new int[200];
        int res = 0;
        // init table
        for(int i = 0; i < chars.length(); i++){
            table[chars.charAt(i)]++;
        }
        for(String s : words){
            if(isMatch(s, table, 0)){
                res += s.length();
            }
        }
        return res;
    }

    private boolean isMatch(String word, int[] table, int index){
        if(index == word.length()) return true;
        if(table[word.charAt(index)] > 0){
            table[word.charAt(index)]--;
            boolean res =  isMatch(word, table, index+1);
            table[word.charAt(index)]++;
            return res;
        }else{
            return false;
        }
    }
}
```
