### 解题思路
此处撰写解题思路

### 代码

```java
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
                //字符的转换为数字需要减去a（97），A（65）
                temp[c-'a']++;
            }
            for(int i = 0; i < charsOfCase.length; i++){//对比两个统计数据
                if(temp[i] > charsOfCase[i]){
                    flag = false;
                }
            }
            if(flag) count += str.length();
        }
        return count;
    }
}
```