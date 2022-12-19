拿到字符串，首先调用trim()方法去掉字符串两端的空格，去掉空格之后有两种情况：（1）字符串只有一个单词；（2）字符串有多个单词，这些单词由空格隔开。那么可以调用contains(" ")方法判断字符串是否含有空格来确定是属于第一种情况还是第二种情况；若是第一种情况则直接返回字符串的长度；若是第二种情况则用split(" ")将字符串转为一个字符数组，则该数组的最后一个元素就是字符串的最后一个单词，返回该元素的长度即可
```
public int lengthOfLastWord(String s) {
        s = s.trim();
        if (s.contains(" "))
        {
            String array[] = s.split(" ");
            return array[array.length-1].length();
        }
        else
            return s.length();
    }
```
