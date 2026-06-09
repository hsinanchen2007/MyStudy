**方法一：HashMap记录字母表**
```
class Solution {
    /**
    * 思路：
    * (1) 创建一个HashMap用来记录字母表中的字母以及每个字母的出现次数；
    * (2) 依次从词汇表中取出单词，遍历每个字母判断是否能在字母表中找到并且够用，
    *   如果字母表中没有当前字母或者个数不够当前单词使用，则跳出循环拼写下一个单词，
    *   如果字母表中有当前字母并且够当前单词使用，则继续循环遍历当前单词直到结束累加当前单词长度。
    */
    public int countCharacters(String[] words, String chars) {
        int ans = 0;
        Map<Character,Integer> map = new HashMap<>(chars.length());
        char[] chs = chars.toCharArray();
        for (char c : chs){
            if(map.containsKey(c)){
                map.put(c,map.get(c) + 1);
            }else {
                map.put(c,1);
            }
        }
        for (String s : words){
            int len = s.length();
            for (int i = 0; i < s.length(); i++){
                if(!map.containsKey(s.charAt(i)) || len - s.replace(s.charAt(i)+"","").length() > map.get(s.charAt(i))){
                    break;
                }
                if(i == len - 1){
                    ans += len;
                }
            }
        }
        return ans;
    }
}
```

**方法二：ASCII字符编码表计数**
```
class Solution {
    /**
    * 思路：
    * (1) 由题创建长度26的int数组用来存储每个小写字母出现的次数；
    * (2) 判断每个单词统计的数组是否所有字母都能被字母表统计的数组覆盖，
    *       如果被覆盖则记录长度拼接单词长度，直到遍历完词汇表中单词。
    */
    public int countCharacters(String[] words, String chars) {
        int[] chars_count = count(chars); // 统计字母表的字母出现次数
        int res = 0;
        for (String word : words) {
            int[] word_count = count(word); // 统计单词的字母出现次数
            if (contains(chars_count, word_count)) {
                res += word.length();
            }
        }
        return res;
    }

    // 检查字母表的字母出现次数是否覆盖单词的字母出现次数
    boolean contains(int[] chars_count, int[] word_count) {
        for (int i = 0; i < 26; i++) {
            if (chars_count[i] < word_count[i]) {
                return false;
            }
        }
        return true;
    }

    // 统计 26 个字母出现的次数
    int[] count(String word) {
        int[] counter = new int[26];
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            counter[c-'a']++;
        }
        return counter;
    }
}
```
