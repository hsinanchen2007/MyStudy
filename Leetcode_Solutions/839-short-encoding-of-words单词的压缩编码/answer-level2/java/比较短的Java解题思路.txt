1、首先对给定的String数组进行排序，按照单词的长度降序排序。
2、假定字符串result是返回结果，初始化String res = ""。
3、遍历数组，比较每个单词是否能在res中表示。单词可以在res中表示的判断条件：res.indexOf(words[i])!= -1 && res.substring(index + words[i].length(), index + words[i].length() + 1)等于"#"。如果可以表示直接忽略，如果不能，则res += words[i] + "#"
4、返回res的长度。

几个tip需要关注：
1、此题不用考虑最终返回的结果，只返回长度，所以可以打乱给定的String数组。
2、比较新出现的单词是否在res中时不仅要看起始字符，还要看以“#”结尾。
3、使用Arrays.sort()对数组进行排序，直接使用lambda表达式，代码非常简洁。

代码：
```
import java.util.Arrays;

/**
 * 820. 单词的压缩编码
 * @since 2019-10-23
 */
public class MinimumLengthEncoding820 {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, (a, b)->b.length() - a.length());
        String res = "";
        for (int i = 0; i < words.length; i++) {
            int index = res.indexOf(words[i]);
            if (index != -1 && res.substring(index + words[i].length(), index + words[i].length() + 1).equals("#")) {
                continue;
            } else {
                res = res + words[i];
                res = res + "#";
            }
        }
        return res.length();
    }

    public static void main(String[] args) {
        MinimumLengthEncoding820 ins = new MinimumLengthEncoding820();
        String[] param1 = new String[] {"time", "me", "bell"};
        System.out.println(ins.minimumLengthEncoding(param1));
        String[] param2 = new String[] {"me", "time"};
        System.out.println(ins.minimumLengthEncoding(param2));
    }
}
```
