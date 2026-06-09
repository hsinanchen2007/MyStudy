### 解法

```java
public int lengthOfLastWord(String s) {
        char[] chars = s.toCharArray();
        if(chars.length == 0)
            return 0;
        int tail = chars.length - 1;
        for(;tail >= 0; tail--){ // 处理"a      "，先找到第一个非空的字符
            if(chars[tail] != ' ')
                break;
        }
        if(tail == -1) // "      "的情况
            return 0;
        int i = tail - 1;
        for(; i >= 0; i--){
            if(chars[i] == ' ')
                break;
        }
        return tail - i;
    }
```

思路分析：

* 以空格为分割符，要找到最后一个单词的长度。首先，如果所给的字符串长度为0，压根不存在字符，直接返回了。
* 最后一个单词，那么我们就从后往前去找第一个单词的结尾字符。注意，字符串可能是以一系列的空格结尾，比如`"a     "`。所以使用一个循环从字符串末尾寻找第一个非空格的字符，其索引用`tail`表示，当遇到第一个不非空格字符`chars[tail] != ' '`，跳出循环。
* 注意如果整个字符串均为空，那么循环结束时`tail == -1`。这种情况下也不存在单词，返回0。
* 最后一个单词的末尾索引找到后，从`int i = tail - 1`，向前找这个单词的第一个字符的前一个索引，当循环遇到空字符时就停止循环，此时`i + 1`为最后一个单词的第一个字符的索引。那么最后一个单词的长度即为`tail - i`。
* 时间复杂度为$O(1)$，空间复杂度为$O(1)$。

运行结果：

* 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
* 内存消耗 :38.1 MB, 在所有 Java 提交中击败了5.43%的用户

更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖