### 解题思路
此处撰写解题思路

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