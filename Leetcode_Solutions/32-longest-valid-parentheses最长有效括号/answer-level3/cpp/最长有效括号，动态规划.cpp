方法一：动态规划自底向上。
时间复杂度$O(n)$，空间复杂度$O(n)$。
思路：
1. 先记录最短的合法括号对【实际就是相邻的 '(' 和 ')' 】。

2. 然后自底向上对合法括号对进行连接、扩充。
    连接是将两个相邻的合法括号对合一；
    扩充是判断现有的合法括号对能否被其两边的括号包含【 () 被另一个 () 包含变成 (()) 】

3. 利用s.size()等长的数组记录合法括号对的起止位置，括号对开始的 '(' 对应数组位置记录的是括号对结束的位置，括号对结束的 ')' 对应数组位置记录的是括号对开始的位置。若记录的值为-1表示该括号暂时无法与其余括号组成合法括号对。

4. 寻找最长的括号对。

例如：
s =“）（）（）”，初始化数组a元素为 -1。

寻找最短的合法括号对，数组a内容：a = [-1， 2， 1， 4， 3]；
a[0] = -1表示 s[0] 处的括号暂时无法和其余括号组成括号对；
a[1] = 2  表示 s[1] 处开始的括号对到s[2]处结束【包含s[2]】;
a[2] = 1  表示 s[2] 处结束的括号对从s[1]处开始;

对括号对进行连接扩充：a = [-1, 4, 1, 4, 1]，此时a[2]，a[3]处的元素已经没用了。

最后查找最长的括号对。

```c
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2) return 0;
        vector<int> a(s.size(), -1);
        //  init vector a = {-1};
        for (int i = 0; i < s.size() - 1; )
            if (s[i] == '(' && s[i + 1] == ')') {
                a[i] = i + 1;
                a[i + 1] = i;
                i += 2;
            } else i++;
        
        //  connection and expansion
        bool ischange = true;
        int i = 0;
        while (ischange) {
            //  connection x and y
            for (i = 0, ischange = false; i < a.size(); ) {
                if (a[i] < 0) i++;
                else if (a[i] + 1 < a.size() && a[ a[i] + 1 ] > 0) {
                    int xbegin = i, xend, ybegin, yend;
                    xend    = a[xbegin];
                    ybegin  = xend + 1;
                    yend    = a[ybegin];
                    a[yend] = xbegin;
                    a[xbegin] = yend;     
                    ischange = true;
                } 
                else i = a[i] + 1;
            }
            
            //  expansion
            for (i = 0, ischange = false || ischange; i < a.size(); ) {
                if (a[i] < 0) i++;
                else if (a[i] > 0 && i - 1 >= 0 && a[i] + 1 < a.size() 
                         && s[i -1] == '(' && s[a[i] + 1] == ')') {
                    a[i -1] = a[i] + 1;
                    a[a[i] + 1] = i - 1;
                    i = i - 1;
                    ischange = true;
                } 
                else i = a[i] + 1;
            }
        }
        
        //  find maxLen;
        int maxLen = 0;
        for (i = 0; i < a.size(); ) {
            if (a[i] == -1) i++;
            else {
                maxLen = max(maxLen, a[i] - i + 1);
                i = a[i] + 1;
            }
        }
        return maxLen;
    }
};
```

方法二：利用栈记录每个 '(' 的位置，start记录合法括号对初始的位置。若遇到 ')' 判断栈是否为空。
栈为空，start记录的位置移动。栈非空则pop，并且更新比较最长括号对。（参考了某位大佬的代码）


```c
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0, start = 0;
        stack<int> p;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(') 
                p.push(i);
            else if (s[i] == ')' && p.empty())
                start = i + 1;
            else {
                p.pop();
                maxLen = p.empty() ? 
                    max(maxLen, i - start + 1) : max(maxLen, i - p.top());
            }
        return maxLen;
    }
};
```

很明显第二种方法更优，只需遍历一次字符串即可。