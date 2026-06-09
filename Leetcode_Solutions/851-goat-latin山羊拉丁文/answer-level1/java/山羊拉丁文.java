### 解题思路
本题不属于算法题，属于Java语言的语法题：
总结几个重要的Java函数吧。
StringBuilder xx=new StringBuilder();  //用来建立字符串的函数
String i:S.split(" ");   //分割字符串
StringBuilder 中的append函数可以连用。如果加入除第一个字母之外的可以append(i.substring(1))
删除函数  answer.deleteCharAt(S.length()-1)


### 代码

```java
class Solution {
    public String toGoatLatin(String S) {
        //本题其实就是一个字符串函数在Java语言中的应用，不涉及算法，涉及语法
        StringBuilder answer=new StringBuilder();
        int index=1;    //用来标志索引的序号
        for(String i:S.split(" "))  //将原有的字符串分割，并对每一个字符处理
        {
            char l=i.charAt(0);
            if(l=='a'||l=='e'||l=='i'||l=='o'||l=='u'||l=='A'||l=='E'|l=='I'||l=='O'||l=='U')
            {
                answer.append(i).append("ma");  //先添加这个字符串，再添加"ma
                for(int j=0;j<index;j++)
                    answer.append('a');
                //单词处理完了，要在后面添加空格
                answer.append(' ');
                index++;   //索引号加一
            }
            else
            {
                answer.append(i.substring(1)).append(l).append("ma");
                for(int j=0;j<index;j++)
                    answer.append("a");
                answer.append(' ');
                index++;
            }
        }
        //删除最后一个多添加的空格
        answer.deleteCharAt(answer.length()-1);
        return answer.toString();
    }
}
```