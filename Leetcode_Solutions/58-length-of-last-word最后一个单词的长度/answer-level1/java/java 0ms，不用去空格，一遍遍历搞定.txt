# 思路
其实思路很简单，从后往前遍历给定字符串，碰到非空格，count++，碰到空格，如果count != 0，说明现在的count就是最后一个单词的长度（这个应该很好想到），则直接返回count即可。如果这个循环没有直接return的话，那么只有以下两种情况：
（1）字符串全部都是空格；
（2）字符串只有一个单词，且这个单词索引从0开始。
以上两种情况，在最后return count即可。 具体还是看看代码吧：

```java
 public int lengthOfLastWord(String s) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }

        int count = 0;
        for (int i = len - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c != ' ') {
                count++;
            } else {
                if (count != 0) {
                    return count;
                }
            }
        }

        return count;
    }
    
```