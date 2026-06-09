### 解题思路
1.使用双指针,i和j同时出发，j走快一些，若S[j] == S[i]，则j继续向前走
2.直到S[j] ！= S[i]，此时相等的长度为j - i，依次将S[i]和长度放进字符串
3.判断sb.Length >= S.Length的情况，取原字符串，否则取最新的

### 代码

```csharp
public class Solution {
public string CompressString(string S)
    {
        int len = S.Length;
        if (len == 0)
        {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0,j = 0; i < len; i++)
        {
            while (j<len&& S[i] == S[j])
            {
                j++;
            }

            int subLen = j - i;
            sb.Append(S[i]);
            sb.Append(subLen);
            i = j - 1;
        }

        if (sb.Length >= S.Length) return S;
        return sb.ToString();
    }
}
```