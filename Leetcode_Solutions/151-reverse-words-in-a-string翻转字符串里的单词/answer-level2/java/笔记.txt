### 解题思路
暴力法？
去看看其他的大佬的操作

### 代码

```java
import java.util.regex.Pattern;

class Solution {
    public String reverseWords(String s) {
        if (s.length() == 0) return "";
        char[] substitute = s.toCharArray();
        int i;
        String pattern="\\S";
        List<String> each_words = new ArrayList<String>();
        //排除开头空格
        for (i = 0; i < substitute.length; i++) {
           StringBuilder trans=new StringBuilder();
           trans.append(substitute[i]);
           if(Pattern.matches(pattern,trans.toString())) break;
        }
        //如果i等于数组长度，则表明全为空格 直接输出
        if (i == substitute.length) return "";

        StringBuilder trans = new StringBuilder();
        
        for (; i < substitute.length; i++) {
            //碰到空格就表明当前单词结束了
            if (substitute[i] == ' ') {
                //这里还应考虑，一连串空格的情况，其意思为上个字符也是空格，则不应该加入List
                //如果上一个也为空格，则trans必为空    
                if(!trans.toString().isEmpty())each_words.add(trans.toString());
                trans = new StringBuilder();
            }
            else trans.append(substitute[i]);
        }
        //如果最后一个单词后面没有空格，则会使得最后一个单词，并没有加入List中
        //所以格外补充
        if(!trans.toString().isEmpty())each_words.add(trans.toString());
        trans = new StringBuilder();
        //逆序输出
        for (i = each_words.size()-1; i >= 0; i--) {
            trans.append(each_words.get(i));
            //一句话的末尾没有空格
            if (i != 0) trans.append(" ");
        }
        return trans.toString();
    }
}

```