## 思路:

首先要理顺题意,给定一堆单词,让你放在固定长度字符串里

1. 两个单词之间至少有一个空格,如果单词加空格长度超过`maxWidth`,说明该单词放不下,比如示例1:当我们保证`this is an` 再加入`example`变成`this is an example`总长度超过`maxWidth`,所以这一行只能放下`this` `is` `an` 这三个单词;
2. `this is an`长度小于`maxWidth`,我们考虑分配空格,并保证左边空格数大于右边的
3. 最后一行,要尽量靠左,例如示例2的:`"shall be        "`

我们针对上面三个问题,有如下解决方案.

1. 先找到一行最多可以容下几个单词;
2. 分配空格,例如`this` `is` `an` ,对于宽度为`maxWidth`,我们可以用`maxWidth - all_word_len` 与需要空格数商为 单词间 空格至少的个数,余数是一个一个分配给左边.就能保证左边空格数大于右边的.例如 `16 - 8 = 8`  ,`a = 8 / 2, b = 8 % 2`两个单词间要有4个空格,因为余数为零不用分配;
3. 针对最后一行单独考虑;

详细的解释写在代码里,大家一步一步从头看一遍,就明白了,如有不明白,可以留言!  不擅长 `Java` 写的好费劲.

## 代码:

```python [1]
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        n = len(words)
        i = 0

        def one_row_words(i):
            # 至少 一行能放下一个单词, cur_row_len
            left = i
            cur_row_len = len(words[i])
            i += 1
            while i < n:
                # 当目前行 加上一个单词长度 再加一个空格
                if cur_row_len + len(words[i]) + 1 > maxWidth:
                    break
                cur_row_len += len(words[i]) + 1
                i += 1
            return left, i

        while i < n:
            left, i = one_row_words(i)
            # 该行几个单词获取
            one_row = words[left:i]
            # 如果是最后一行了
            if i == n :
                res.append(" ".join(one_row).ljust(maxWidth," "))
                break
            # 所有单词的长度
            all_word_len = sum(len(i) for i in one_row)
            # 至少空格个数
            space_num = i - left - 1
            # 可以为空格的位置
            remain_space = maxWidth - all_word_len
            # 单词之间至少几个空格,还剩几个空格没用
            if space_num:
                a, b = divmod(remain_space, space_num)
            # print(a,b)
            # 该行字符串拼接
            tmp = ""
            for word in one_row:
                if tmp:
                    tmp += " " * a
                    if b:
                        tmp += " "
                        b -= 1
                tmp += word
            #print(tmp, len(tmp))
            res.append(tmp.ljust(maxWidth, " "))
        return res
```

 



```java [1]
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int i = 0;
        int n = words.length;
        while (i < n) {
            // 找到一行可以容下单词
            int left = i;
            // 至少一行能放下一个单词
            int cur_row_len = words[i].length();
            i++;
            
            while (i < n) {
                if (cur_row_len + words[i].length() + 1 > maxWidth) break;
                ;
                cur_row_len += words[i].length() + 1;
                i++;
            }
            //System.out.println(left);
            //System.out.println(i);
            StringBuilder tmp = new StringBuilder();
            // 考虑最后一行
            if (i == n) {
                for (int j = left; j < i; j++) {
                    tmp.append(words[j] + " ");
                }
                tmp.deleteCharAt(tmp.length() - 1);
                for (int j = tmp.length(); j < maxWidth; j++)
                    tmp.append(" ");
                res.add(tmp.toString());
                break;
            }
            // 所有单词长度
            int all_word_len = 0;
            for (int j = left; j < i; j++) {
                all_word_len += words[j].length();
            }
            //System.out.println(all_word_len);
            // 至少空格个数
            int space_num = i - left - 1;
            // 可以为空格的位置个数
            int remain_space = maxWidth - all_word_len;
            int a = 0;
            int b = 0;
            if (space_num != 0) {
                a = remain_space / space_num;
                b = remain_space % space_num;
            }
            for (int j = left; j < i; j++) {
                if (tmp.length() > 0) {
                    for (int k = 0; k < a; k++) tmp.append(" ");
                    if (b != 0) {
                        tmp.append(" ");
                        b--;
                    }
                }
                tmp.append(words[j]);
            }
            for (int j = tmp.length(); j < maxWidth; j++) {
                tmp.append(" ");
            }
            res.add(tmp.toString());
        }
        return res;
    }
}
```

