### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] chars_count = count(chars);
        int res = 0;
        for(String word:words){
            int[] word_count = count(word);//统计单词的字母出现次数
            if(contains(chars_count,word_count)){

                res += word.length();
            }
        }
        return res;

    }

    //检查字母表的字母出现次数是否覆盖单词种的字母出现次数
    boolean contains(int[] chars_count, int[] word_count){
        for(int i = 0; i < 26; i++){
            if(chars_count[i] < word_count[i]){
                return false;
            }
        }
        return true;
    }

    //统计2266个字母出现的次数

    int[] count(String word){
        int[] counter = new int[26];
        for(int i =0 ; i<word.length();i++){
            char c = word.charAt(i);
            counter[c-'a']++;
        }

        return counter;
    }
}
```