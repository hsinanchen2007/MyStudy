利用Map的key唯一性，每次遍历都将单词中字符所在chars中的索引保存至map中，循环完成一次后比较单词跟map的长度，相等则是可以拼写出的单词。
方式可能不太好，但也算是一种题解思路吧。

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        String [] original = words;
        char [] charsArr =  chars.toCharArray();
        Map<Integer,Character> tempIndexMap = new HashMap();
        int result = 0;
        for ( String temp : original ){
            char [] originalCharArr = temp.toCharArray();
            for ( char tempChar : originalCharArr ){
                aa:
                for ( int i = 0; i < charsArr.length; i++ ){
                    if ( tempChar == charsArr[i] && !tempIndexMap.containsKey(i) ){
                        tempIndexMap.put(i,tempChar);
                        break aa;
                    }
                }
            }
            if ( originalCharArr.length == tempIndexMap.size() ){
                result += originalCharArr.length;
            }
            tempIndexMap.clear();
        }

        return result;
    }
}
```