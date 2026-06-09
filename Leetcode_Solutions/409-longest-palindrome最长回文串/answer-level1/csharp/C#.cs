### 解题思路
要是回文数的话，左右对称
1.若字符总数为偶数，则肯定是回文数；若为奇数，则中间一位为奇数。
2.先计算每种字符出现的次数
3.计算其中为偶数的字符的数量
4.若总数小于字符串的长度，可以添加一位放在中间

### 代码

```csharp
public class Solution {
    public int LongestPalindrome(string s) {
                int res = 0;
                int[] sPalind  =new int[58];
                for (int i = 0; i < s.Length; i++)
                {
                    sPalind[s[i] - 'A']++;
                }

                for (int i = 0; i < sPalind.Length; i++)
                {
                    res += sPalind[i] / 2 * 2;
                }

                if (res < s.Length)
                    res++;
                return res;
    }
}
```