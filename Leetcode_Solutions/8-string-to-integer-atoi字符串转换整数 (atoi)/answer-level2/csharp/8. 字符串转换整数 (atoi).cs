```
/**
    1、while 判断起始位置
    2、while 判断结束位置
    3、while a、将数字字符转为int * 符号（1 / -1）
            b、索引位置 * 10 （乘前判断是否越界）
            c、索引值累加（累加前判断是否越界）
 */
public class Solution {
    public int MyAtoi(string str) {
        char positiveSymbol = '+';
        char negativeSymbol = '-';
        char symbol = positiveSymbol;
        char spaceChar = ' ';
        char value;
        string nums = "0123456789";
        int defalultAns = 0;
        int index = 0;
        int length = str.Length;
        // 确定起始位置
        while (index < length) {
            value = str[index];
            index++;
            if (value == spaceChar) {
                continue;
            } else if (value == positiveSymbol || value == negativeSymbol) {
                symbol = value;
                if (index == length) {
                    return defalultAns;
                }
                str = str.Substring(index);
                break;
            } else if (nums.IndexOf(value) != -1) {
                str = str.Substring(index - 1);
                break;
            } else {
                return defalultAns;
            }
        }
        index = 0;
        length = str.Length;
        // 确定结束位置
        while (index < length) {
            value = str[index];
            if (nums.IndexOf(value) == -1) {
                str = str.Substring(0, index);
                break;
            }
            index++;
        }
        index = 0;
        length = str.Length;
        int symbolInt = 1;
        defalultAns = int.MaxValue;
        if (symbol == '-') {
            symbolInt = -1;
            defalultAns = int.MinValue;
        }
        int valueIndex = 0;
        int ans = 0;
        while (index < length) {
            valueIndex = symbolInt * (str[index] - '0');
            int multiply = (length - index - 1);
            while (multiply-- > 0) {
                // 判断是否越界
                if (valueIndex > (int.MaxValue / 10) || valueIndex < (int.MinValue / 10)) {
                    return defalultAns;
                }
                valueIndex *= 10;
            }
            // 判断是否越界
            if ((symbolInt == 1 && ans > int.MaxValue - valueIndex) || (symbolInt == -1 && ans < int.MinValue - valueIndex)) {
                return defalultAns;
            }
            ans += valueIndex;
            index++;
        }
        return ans;
    }
}
// Accepted
//     1079/1079 cases passed (100 ms)
//     Your runtime beats 68.62 % of csharp submissions
//     Your memory usage beats 25.56 % of csharp submissions (24.2 MB)
```
