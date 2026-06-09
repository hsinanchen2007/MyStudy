### 解题思路
作为一只菜鸡我没用字典树......而是直接用StringBuilder匹配字符串
有个坑不知道是不是只有我一开始没反应过来,就是比对时需要比对words[i]+"#"而不是单纯比对words[i],因为需要保证比对的词是其他词的后缀,才能通过识别#还原单词

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        StringBuilder builder=new StringBuilder("");
        Arrays.sort(words, (s1, s2) -> s2.length() - s1.length());//按长度排序
        for(int i=0;i<words.length;i++){       
            if(builder.indexOf(words[i]+'#')<0){
                builder.append(words[i]+"#");
            }
        }
        return builder.length();
    }
}
```