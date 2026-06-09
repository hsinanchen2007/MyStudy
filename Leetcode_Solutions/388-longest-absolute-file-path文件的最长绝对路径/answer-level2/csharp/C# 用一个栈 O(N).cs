通过`\n`可以判断是不是一个新的目录开始
通过`\t`可以判断这个文件夹是第几级
自然想到用栈来维护文件夹的层级结构比较方便
用`tabCount`计算当前目录的层级

ps:比想象的简单点

```
public class Solution {
    public int LengthLongestPath(string input) {
        var stack = new Stack<int[]>();
        var isFile = false;
        var len = 0;
        var tabCount = 0;
        var result = 0;
        for (int i = 0; i <= input.Length; i++) {
            if (i == input.Length || input[i] == '\n') {
                while (stack.Count > 0 && tabCount <= stack.Peek()[0]) {
                    stack.Pop();
                }
                stack.Push(new int[2] { tabCount, len });
                if (isFile == true) {
                    var parts = stack.ToArray();
                    var sum = 0;
                    foreach (var p in parts) {
                        sum += p[1];
                    }
                    sum += parts.Count() - 1;
                    result = Math.Max(result, sum);
                    isFile = false;
                }
                tabCount = 0;
                len = 0;
            } else if (input[i] == '\t') {
                tabCount++;
            } else if (input[i] == '.') {
                isFile = true;
                len++;
            } else {
                len++;
            }
        }
        return result;
    }
}
```
