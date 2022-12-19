执行用时 : 116 ms, 在Basic Calculator的C#提交中击败了100.00% 的用户     
内存消耗 : 22.1 MB, 在Basic Calculator的C#提交中击败了100.00% 的用户
    
```csharp
public class Solution {
    private int i = -1; // 指针
    private string s;
    public int Calculate(string s) {
        this.s = s;
        return Parse();
    }
    public int Parse() {
        int ans = 0; // 计算结果
        bool plus = true; // true:加号, false:减号
        while (i < s.Length - 1) {
            i++;
            switch (s[i]) {
                case ' ': // 忽略空格
                    continue;
                case '+':
                    plus = true;
                    continue;
                case '-':
                    plus = false;
                    continue;
                case '(': // 遇到左括号表明有新的优先计算区域
                    if (plus) ans += Parse(); // 这里可以直接忽略括号，不过因为需要改右括号的处理，所以懒得优化
                    else ans -= Parse();
                    continue;
                case ')': // 遇到没有处理的右括号表明优先区域结束
                    return ans;
                default: // 遇到数字
                    if (plus) ans += ParseInt();
                    else ans -= ParseInt();
                    continue;
            }
        }
        return ans;
    }
    public int ParseInt() {
        int ans = 0;
        for (; i < s.Length && char.IsDigit(s[i]); i++) {
            ans *= 10;
            ans += s[i] - '0';
        }
        i--;
        return ans;
    }
}
```