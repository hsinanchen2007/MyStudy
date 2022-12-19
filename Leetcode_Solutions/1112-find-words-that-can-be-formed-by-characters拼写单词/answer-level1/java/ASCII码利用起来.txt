### 解题思路
将chars中所有字符的数量计算存储起来
遍历words中每一个单词words[i]中每个字符出现的数量
与chars中同一字符的数量进行对比，如果words[i]中当前字符数量大于chars中同一字符的数量，则不满足条件直接跳出，舍弃当前单词
若遍历完，满足条件，则将当前单词的长度加上

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charLen = new int[26];
        for(char c : chars.toCharArray() ){
            charLen[c - 'a'] ++;
        }

        int res =0;
       

        for(int i = 0;i<words.length;i++){
            int[] tmp = new int[26];
            boolean flag = true;
            for(char j : words[i].toCharArray()){
                tmp[j - 'a']++;
                if(tmp[j - 'a'] > charLen[j - 'a']){
                    flag = false;
                    break;
                }
            }
            if(flag) res += words[i].length();
        }
        return res;
    }
}
```