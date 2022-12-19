# 思路
同47题，47是数字的全排列，本题是字符的全排列

# 注意事项
1.会了第40题后，这题大部分就是怎么把数字的题转为字符串的处理。例如用sb来存储字符串，类比于用list来存储数字；例如把String转换为字符串数组；字符串数组也可以排序；sb怎么删掉最后一个字符；sb用append来添加字符。
2.注意字符串里的字符是可以重复的，所以不是46题的全排列，而是47题的全排列，区别就是原始元素是否可以重复。
3.先排序，后剪枝。

# 代码
```
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public String[] permutation(String s) {
        List<String> result = new ArrayList<>();
        String[] stringRes = new String[result.size()];
        if (s == null || s.length() == 0) {
            return result.toArray(stringRes);
        }
        char[] sChar = s.toCharArray();
        Arrays.sort(sChar);
        boolean[] flag = new boolean[sChar.length];
        StringBuilder sb = new StringBuilder();
        dfs(result, sb, sChar, flag, 0);
        return result.toArray(stringRes);
    }

    private void dfs(List<String> result, StringBuilder sb, char[] sChar, boolean[] flag, int index) {
        if (sb.toString().length() == sChar.length) {
            result.add(sb.toString());
            return;
        }
        for (int i = 0; i < sChar.length; i++) {
            if (flag[i]) continue;
            if (i > 0 && sChar[i] == sChar[i - 1] && !flag[i - 1]) {
                continue;
            }
            sb.append(sChar[i]);
            flag[i] = true;
            dfs(result, sb, sChar, flag, i + 1);
            sb.deleteCharAt(sb.length() - 1);
            flag[i] = false;
        }
    }
}

```
