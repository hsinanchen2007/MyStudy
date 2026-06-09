### 解题思路
spilt()以" "切割字符串时，当有多个空格时，例如” hello world“->"","hello","world"  "   hello world!"->"","","","hello","world!"
所以舍去”“，然后用append 加入字符串，最后返回时要注意删除字符串首尾空格

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String string ="";
        if(s==null){
            return string;
        }
        String []str = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(int i= str.length-1;i>=0;i--){
            if(str[i].equals("")) continue ;
            sb.append(str[i]);
            sb.append(" ");
           
        }
        //trim() 删除首尾空格
        return sb.toString().trim();


    }
}
```