
**算法：**
- 我们需要逐行分析源代码。有两种情况，要么在一个注释内或者不在。
- 如果我们遇到注释块符号，而我们不在注释中，那么我们将跳过接下来的两个字符，并将状态更改为在注释中。
- 如果我们遇到注释块符号并且我们在注释中，那么我们将跳过接下来的两个字符并将状态更改为不在注释中。
- 如果我们遇到一个行注释且我们不在注释中，那么我们将忽略该行的其余部分。
- 如果我们不在注释中（并且它不是注释的开头），我们将记录所遇到的字符。
- 在每行的末尾，如果我们不在注释中，我们将记录该行。

```Python [ ]
class Solution(object):
    def removeComments(self, source):
        in_block = False
        ans = []
        for line in source:
            i = 0
            if not in_block:
                newline = []
            while i < len(line):
                if line[i:i+2] == '/*' and not in_block:
                    in_block = True
                    i += 1
                elif line[i:i+2] == '*/' and in_block:
                    in_block = False
                    i += 1
                elif not in_block and line[i:i+2] == '//':
                    break
                elif not in_block:
                    newline.append(line[i])
                i += 1
            if newline and not in_block:
                ans.append("".join(newline))

        return ans
```

```Java [ ]
class Solution {
    public List<String> removeComments(String[] source) {
        boolean inBlock = false;
        StringBuilder newline = new StringBuilder();
        List<String> ans = new ArrayList();
        for (String line: source) {
            int i = 0;
            char[] chars = line.toCharArray();
            if (!inBlock) newline = new StringBuilder();
            while (i < line.length()) {
                if (!inBlock && i+1 < line.length() && chars[i] == '/' && chars[i+1] == '*') {
                    inBlock = true;
                    i++;
                } else if (inBlock && i+1 < line.length() && chars[i] == '*' && chars[i+1] == '/') {
                    inBlock = false;
                    i++;
                } else if (!inBlock && i+1 < line.length() && chars[i] == '/' && chars[i+1] == '/') {
                    break;
                } else if (!inBlock) {
                    newline.append(chars[i]);
                }
                i++;
            }
            if (!inBlock && newline.length() > 0) {
                ans.add(new String(newline));
            }
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(S)$。$S$ 指的是源代码的长度。
* 空间复杂度：$O(S)$，将源代码记录到 `ans` 中所使用的空间。