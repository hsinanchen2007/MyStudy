私以为，本解法的思路比较直接，代码有些臃肿，好在效率还不算太低，**Java 1ms，34.8MB**，仅供大家参考。

比较绕的解释先给出了，大家可以先看代码，有一部分注释说不清楚，就放在正文里说：

**现已知本行内有至少2个单词，除去每个单词间隔必须的1个空格外，还需填补`left_blank`个空格。**

**粗略的想法是，在每个单词间隔中填补`left_blank / (words_num - 1)`个空格。**

**仔细考虑，如果有6个空格需要填补进4个间隙，那么应该是2，2，1，1个空格分配，所以我们用`left_blank`对`(words_num - 1)`取余，且记余数为`mod`，前`mod`个间隙，应该在`left_blank / (words_nums - 1)`个空格基础上再多加1个空格，后面的间隙就不多加那1个空格了**

**这样便是把`mod`个空格均匀分配到了前几个间隙中。**

```
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> result = new ArrayList<>();
        int line_length = 0;
        int left_blank = 0;
        int words_num = 0;
        StringBuilder line = new StringBuilder();
        int i = 0;
        int j = 0;
        while (i < words.length) { // 对所有单词遍历
            words_num = 1; // 每行的单词数
            left_blank = 0; // 每行中，除去每个单词间的空格，还需填补的空格数
            line = new StringBuilder();
            line.append(words[i]); // 第一个单词
            line_length = words[i].length(); // 第一个单词长度
            /* 从i+1个单词开始遍历，贪心选取本行单词的索引右边界j */
            /* 其中line_length变量包含了单词长度总和，以及每个单词间隔1个空格的长度 */
            j = i + 1;
            while (j < words.length && line_length + 1 + words[j].length() <= maxWidth) {
                words_num ++;
                line_length += 1 + words[j].length();
                j ++;
            }
            left_blank = maxWidth - line_length; // 剩余需要填补的空格数
            if (words_num == 1) { // 本行只有一个单词，左端对齐填补left_blank
                line.append(constructBlank(left_blank));
            } else if (j <= words.length - 1) { // 本行有至少两个单词，但不是最后一行，两端对齐填补
                for (int k=i+1; k<j; k++) { // 从第二个单词开始，先拼接空格，再拼接单词
                    /* 这里的填补逻辑见if条件，详细解释见正文 */
                    if (k <= i + (left_blank % (words_num - 1))) {
                        line.append(constructBlank(left_blank / (words_num - 1) + 2));
                    } else {
                        line.append(constructBlank(left_blank / (words_num - 1) + 1));
                    }
                    line.append(words[k]);
                }
            } else { // 本行有多个单词，但是最后一行，仍然左端对齐填补
                for (int k=i+1; k<j; k++) {
                    line.append(" ");
                    line.append(words[k]);
                }
                line.append(constructBlank(left_blank));
            }
            result.add(line.toString()); // 本行字串加入结果
            i = j; // 更新指针
        }
        return result;
    }

    // 构造num个空格的空格字串
    public StringBuilder constructBlank(int num) {
        StringBuilder blank = new StringBuilder();
        for (int i=0; i<num; i++) {
            blank.append(" ");
        }
        return blank;
    }
}
```
