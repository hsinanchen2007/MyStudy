判断字符串是否为空，空直接返回0；
利用split函数将字符串切分成字符数组，直接返回数组最后一个元素的长度。

注意：再返回数组最后一个元素长度之前要先判断数组是否为空，因为有可能题目输入“ ”（一个空格）。

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s == null)
            return 0;
        String []word = s.split(" ");
        if(word.length == 0)  //输入“ ”的情况
            return 0;
        else
            return word[word.length - 1].length();
    }
}
```
