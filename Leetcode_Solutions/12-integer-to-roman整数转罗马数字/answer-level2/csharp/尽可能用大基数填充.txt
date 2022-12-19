### 解题思路
- 先构建基数数组，从小到大排列，未来的输入num将由这些基数的倍数组成；
- 从最大基数开始往前遍历，如果该基数dicNum[i]比输入num大，则跳过，直奔下一个基数；
- 求出输入num与当前基数dicNum[i]的商quotient，说明输入最多能包含quotient个该基数dicNum[i]，将quotient个基数对应的罗马字母dic[i]追加到输出末尾,将输入num替换为余数（num - dicNum[i] * quotient），相当于被quotient个基数dicNum[i]填充后剩下来的空间，这些空间交由更小的基数填充；
- 如果某次填充后，剩余空间为0，说明填充完毕，直接进入最后一步输出字符串；
- 思路就是，尽可能的先用大的基数填充num，在保证不溢出的情况下，只要没填满，就把剩余空间交给较小的基数填充，直至填满。

### 代码

```csharp
public class Solution {
    public string IntToRoman(int num) {
            string[] dic = new string[] { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
            int[] dicNum = new int[] { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
            StringBuilder sb = new StringBuilder();
            for (int i = dic.Length - 1; i >= 0; i--)
            {
                if (dicNum[i] > num)
                {
                    continue;
                }
                int quotient = num / dicNum[i];
                num -= dicNum[i] * quotient;
                for (int j = 0; j < quotient; j++)
                {
                    sb.Append(dic[i]);
                }
                if (num == 0)
                {
                    break;
                }
            }
            return sb.ToString();
    }
}
```