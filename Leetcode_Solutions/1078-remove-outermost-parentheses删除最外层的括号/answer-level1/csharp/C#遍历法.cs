执行结果：
通过
显示详情
执行用时 :
140 ms
, 在所有 C# 提交中击败了
80.00%
的用户
内存消耗 :
21.5 MB
, 在所有 C# 提交中击败了
83.33%
的用户


public class Solution {
    public string RemoveOuterParentheses(string S) {
        StringBuilder stringBuilder = new StringBuilder();
            StringBuilder sb = new StringBuilder();
            int number = 0;
            foreach (var s in S)
            {
                switch (s)
                {
                    case '('://是左括号的情况
                        sb.Append(s);
                        number++;
                        break;
                    case ')'://是右括号的情况
                        sb.Append(s);
                        number--;
                        break;
                    default://其他情况
                        sb.Append(s);
                        break;
                }
                if (number == 0 || sb[0].ToString() != "(")
                {
                    if (sb[0].ToString() != "(")
                    {
                        stringBuilder.Append(sb);
                        sb.Clear();
                    }
                    else
                    {
                        sb.Remove(0, 1);
                        sb.Remove(sb.Length - 1, 1);
                        stringBuilder.Append(sb);
                        sb.Clear();
                    }
                }
            }

        return stringBuilder.ToString();
    }
}

遍历所有字符，遇到左括号number自增，遇到右括号number自减，遇到其他字符直接拼接进去
如果number等于0而首字母不为其他字符就代表字符串已经查找出一个独立括号了
然后删除最外层括号，放入另一个输出储存里
而如果number等于0而首字母为其他字符，证明该字符跟最外层括号属于同一级，直接拼接到输出字符串中。

（如有不对，还请指出。如果其他思路也请写出，共同进步，谢谢）