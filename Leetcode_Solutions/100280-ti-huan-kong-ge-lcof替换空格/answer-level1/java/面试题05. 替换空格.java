### 解题思路
本题直接使用string.replace()这个api就可以解决。不过这个api底层基于规则表达式来做字符的查找，效率低。
使用char数组或者StringBuilder来存储字符。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if (s==null || s.length()==0){
            return s;
        }
        // 使用StringBuilder来拼接字符
        StringBuilder returnS=new StringBuilder();
        for(int i=0; i<s.length(); i++){
            char c=s.charAt(i);
            if(c==' '){
                // 当字符为空格时，在returnS后面拼接"%20"
                returnS.append("%20");
            }else{
                // 否则，拼接当前字符
                returnS.append(c);
            }
        }
        return new String(returnS);
    }
}
```
```java
class Solution {
    public String replaceSpace(String s) {
        if (s==null || s.length()==0){
            return s;
        }
        // 使用char数组来拼接字符
        char[] array=new char[s.length()*3];
        int size=0;
        for(int i=0; i<s.length(); i++){
            char c=s.charAt(i);
            if(c==' '){
                array[size++]='%';
                array[size++]='2';
                array[size++]='0';
            }else{
                array[size++]=c;
            }
        }
        return new String(array, 0, size);
    }
}
```
