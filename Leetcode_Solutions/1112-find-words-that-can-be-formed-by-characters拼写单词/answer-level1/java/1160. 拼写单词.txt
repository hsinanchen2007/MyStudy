```
class Solution {
    /**
    涉及到字母表计数的问题可以用一个长度为 26 的数组来进行计数，是字符串计数问题中的技巧。

    1.用数组count_chars保存字母表里每个字母出现的次数
    2.对词汇表中的每个单词，用数组count_word保存里面每个字母出现的次数
    3.比较数组count_chars与数组count_word的对应位置
    如果count_word中的都不大于count_chars中对应位置的值，就说明该词可以被拼写出，将当前word的长度累加到结果中
    **/
    public int countCharacters(String[] words, String chars) {
        int[] count_chars = count(chars);   //统计字母chars中每个字母出现的次数
        int sumLen = 0;
        for(int i=0; i<words.length; i++){  //对于words中的每个单词，统计其每个字母出现的次数
            int[] count_word = count(words[i]);
            if(compareWord(count_chars,count_word)) 
                sumLen += words[i].length();
        }
        return sumLen;
    }
    public int[] count(String word){
        int[] count = new int[26];
        for(int i=0; i<word.length(); i++){
            char ch = word.charAt(i);
            count[ch - 'a'] += 1;
        }
        return count;
    }
    public boolean compareWord(int[]chars, int[]word){
        for(int i=0; i<26; i++){
            if(chars[i]<word[i]) return false;
        }
        return true;
    }
}
```
