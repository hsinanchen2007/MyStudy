### 执行用时0ms，击败100%的java提交
使用了两个int[]数组作为哈希表：
1. 第一个长度为26，算上大小写共有52个字母，但可以在检测时对每一个字符作大小写转换，统一为大写或小写，因此哈希表大小为26。此哈希表用于记录每个字母在键盘上对应的行号。
2. 第二个长度为words.length，用于记录满足要求的字符串在words[]数组中的位置，最后将它们取出存入output[]数组输出。

综上，使用两个哈希表，存好26个英文字母所在键盘上的行号后，就可以开始检查words：对每个字符串的每个字符，只要有一个字母行号和之前字母的不一样，break跳过；否则记录下这个字符串用于输出。

时间复杂度：O(n)。必须遍历所有字符。
空间复杂度：O(n)。mark[]数组的长度。

### 代码

```java
class Solution {
    public String[] findWords(String[] words) {
        String[] keyboard = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int[] hash = new int[26];
        int[] mark = new int[words.length];
        int cnt = 0;
        for(int i = 0; i < keyboard.length; i++)
        {
            char[] line = keyboard[i].toCharArray();
            for(char c : line)
                hash[c-'a'] = i;
        }
        for(int i = 0; i < words.length; i++)
        {
            char[] t = words[i].toCharArray();
            if(t[0] >= 'A' && t[0] <= 'Z')
                t[0] += 32;
            int j = 1;
            while(j < t.length)
            {
                if(t[j] >= 'A' && t[j] <= 'Z')
                    t[j] += 32;
                if(hash[t[j] - 'a'] != hash[t[j-1] - 'a'])
                    break;
                j++;
            }
            if(j == t.length)
                mark[cnt++] = i;
        }
        String[] output = new String[cnt];
        for(int i = 0; i < cnt; i++)
            output[i] = words[mark[i]];
        return output;
    }
}
```