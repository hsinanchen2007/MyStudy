
第一次for循环，把所有可以用的单词储存在chas数组中，下表表示ascii码与'a'的差值，数字表示该字母的个数

第二次for循环的第一层目的是在words字符串数组中取出第i个字符串word，res先加上该word的长度（如果字母不够拼写会再减去）
     第二层for循环 先将之前可用的chas克隆到temp中，将字符逐个减去，如果出现负数说明字母不够用，减去其字符串长度

最后返回结果

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if (words==null||chars==null)
            return 0;
        int res =0;
        char[] ch = chars.toCharArray();
        int [] chas=new int[26];
        for (char c : ch) {
            chas[c-'a']++;
        }
        for (String word : words) {
            int[] temp=chas.clone();
            res+=word.length();
            for (char c : word.toCharArray()) {
                if (--temp[c-'a']<0){
                    res-=word.length();
                    break;
                }
            }
        }
        return res;
    }
}
```
