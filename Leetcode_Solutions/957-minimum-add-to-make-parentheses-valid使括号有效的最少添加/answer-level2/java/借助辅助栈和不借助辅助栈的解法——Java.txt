# 借助辅助栈
思路：借助辅助栈，遍历字符串，遇到左括号就入栈，遇到右括号，如果栈非空，从栈中弹出一个左括号（表示匹配了一个有效的括号），否则不匹配的括号就要+1，注意：遍历完成之后，栈中可能还存在不匹配的左括号，不要遗漏了。
<br/><br/>
代码：
```
class Solution {
    public int minAddToMakeValid(String S) {
        Stack<Character> stack = new Stack<>();
        
        int ans = 0;
        
        for (int i = 0;i < S.length();i++) {
            char ch = S.charAt(i);
            if (ch == '(') {
                stack.push(ch);
            } else {
                if (!stack.isEmpty()) {
                    stack.pop();
                } else {
                    ans++;// 不匹配的右括号
                }
            }
        }
        
        ans += stack.size();// 不匹配的左括号
        
        return ans;
    }
}
```
<br/><br/>
# 不借助辅助栈
思路：整体思路和借助辅助栈相差不多。具体：不借助辅助栈，而是改为标志左括号数量的变量，遍历字符串，遇到左括号变量就+1，遇到右括号，如果变量大于0，那么变量-1（表示匹配了一个有效的括号），否则不匹配的括号就要+1，注意：遍历完成之后，可能还存在不匹配的左括号，不要遗漏了。
<br/><br/>
代码：
```
class Solution {
    public int minAddToMakeValid(String S) {
        int left = 0;
        int ans = 0;
        
        for (int i = 0;i < S.length();i++) {
            char ch = S.charAt(i);
            if (ch == '(') {
                left++;
            } else {
                if (left > 0) {
                    left--;
                    continue;
                }
                ans++;
            }
        }
        
        ans += left;
        
        return ans;
    }
}
```
<br/><br/>
类似题目：[删除最外层的括号](https://leetcode-cn.com/problems/remove-outermost-parentheses/)
<br/><br/>
效率分析：不使用辅助栈由于减少了入栈和出栈操作，时间上节约了不少，不过两种的算法时间复杂度都是O(n)，n是字符串长度。借助辅助栈的算法空间复杂度最大为O(n)，另一个则为O(1)。
![image.png](https://pic.leetcode-cn.com/41e14bfdd2817e62c1858d7d55aeab171d4a8ab7e4fb9fe7e6009dcfa25dc3d1-image.png)