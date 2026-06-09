
遍历字符串s，构造一维数组link = new int[s.length() + 1]存储当前')'对应的上一个'('的位置

如：)((()))()(()))()((
```
0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
   )    (    (    (    )    )    )    (    )    (    (    )    )    )    (    )    (    (
-1   -1   -1   -1   -1   3    2    1    -1   7    -1   -1   10   9    -1   -1   14   -1   -1 
```

之后从后往前遍历link数组，不为-1的项能够构成有效括号（假设为m)，将link[m]取出，即是对应括号的前面位置，继续判断link[link[m]]，知道值为-1，此时找到了一串有效括号字符串。找到一串后将指针减1继续寻找，直到结束

编程
```java
class Solution {
    public int longestValidParentheses(String s) {
        
        int[] leftStack = new int[s.length()]; // 左括号的位置栈
        int stackCount = 0;
        int[] link = new int[s.length() + 1]; // 右括号链接到上一个左括号的位置
        Arrays.fill(link, -1);

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            if (c == '(') {
                leftStack[stackCount++] = i;
            } else {
                if (stackCount > 0) {
                    int leftPos = leftStack[--stackCount];
                    link[i + 1]  = leftPos;
                }
            }
        }

        int maxLen = 0; // 最大的长度
        int i = link.length - 1;
        while (i > 0) {
            if (link[i] != -1) {
                int j = link[i];
                while (j != 0 && link[j] != -1) {
                    j = link[j];
                }
                if (i - j > maxLen) {
                    maxLen = i - j;
                }
                i = j;
            } else {
                i--;
            }
        }
        return maxLen;
    }
}
```