```
    public boolean detectCapitalUse(String word) {
        if (word.equals(word.toUpperCase())) {
            return true;
        } else if (word.toLowerCase().equals(word)) {
            return true;
        }else{
            if (word.substring(1, word.length()).toLowerCase().equals(word.substring(1, word.length()))) {
                return true;
            }else{
                return false;
            }
        }
    }
```
正确的单词只有三种情况：
1、全部大写--->对比原来的字符串和全部换成大写字母之后的字符串是否相等
2、全部小写--->对比原来的字符串和全部换成小写字母之后的字符串是否相等
3、只有第一个字母大写--->对比subString(1,word.length())后面的部分和后面这部分换成小写之后的字符串是否相等