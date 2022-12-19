1. 统计字符表中各自字符所出现的次数；
2. 对词汇表中的每个单词也做上述统计；
3. 比较1,2；如果1中各个字符出现的次数总是大于等于2，则符合要求；

```
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charsOfCase = new int[26];//统计字符表中的字符
        int count = 0;//单词长度之和

        for(char c : chars.toCharArray()){//统计字符表中的字符
            charsOfCase[c-'a']++;
        }
        for(String str : words){
            int[] temp = new int[26];
            boolean flag = true;
            for(char c : str.toCharArray()){//存储统计词汇表中单词的字符
                temp[c-'a']++;
            }
            for(int i = 0; i < charsOfCase.length; i++){//对比两个统计数据
                if(temp[i] > charsOfCase[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) count += str.length();
        }
        return count;
    }
}
```
