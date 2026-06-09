Java中的 String的split  函数是用于按指定字符（串）或正则去分割某个字符串，结果以字符串数组形式返回，split("\\s+")\s表示匹配任何空白字符，+表示匹配一次或多次。string.trim()去掉字符串首尾的空格

```
class Solution {
    public String reverseWords(String s) {
        String[] str=s.split("\\s+");
        StringBuffer buffer=new StringBuffer();
        for(int i=str.length-1;i>=0;i--){
            buffer.append(str[i]);
            buffer.append(" ");
        }
        return buffer.toString().trim();

    }
}
```
