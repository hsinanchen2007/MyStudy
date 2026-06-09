### 解题思路
1. 考虑字符串为空或者只含有空格：返回0


2. 考虑字符串为一个或多个单词:
    法1： 1 ms	37.9 MB
            使用java 中提供的split函数根据空格将单词分割开，这会返回一个数组，把数组最后一个单词的长度返回即可
    法2： 0 ms	37.3 MB
            使用for循环，从后往前数，第一次出现非空格时，做个标记，并且计数加一，当出现空格并且已标记，说明最后一个单词已经计数完成，返回计数

### 代码 法1

```java
class Solution {
    public int lengthOfLastWord(String s) {
        //若s为'' 或' '
        if(s==null||s.length()==0||s.trim().equals("")){
            return 0;
        }
        //若包含多个单词
        String[] strs=s.split(" ");
        return strs[strs.length-1].length();
    }
}
```

### 代码 法2
```java 
class Solution {
    public int lengthOfLastWord(String s) {
        //若s为'' 或' '
        if(s==null||s.length()==0||s.trim().equals("")){
            return 0;
        }
        //从后往前
        char ch;
        int count=0;
        boolean f=false;
        for(int i=s.length()-1;i>=0;i--){
            ch=s.charAt(i);
            if(ch!=' '){
                count++;
                f=true;
            }
            else if(ch==' '&&f){
                break;
            }
        }
        return count;
    }
}
```
