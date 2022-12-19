### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public string CompressString(string S) {
        if(S.Length < 1)
        {
            return S;
        }
        StringBuilder sb = new StringBuilder();

        char step = S[0];
        int j = 0;
        for(int i = 0; i < S.Length; i++)
        {
                if(step == S[i])
                {
                    j++;
                }
                else{

                    sb.Append(step);
                    sb.Append(j);

                    step = S[i];
                    j = 1;
                }

                if(i == S.Length -1)
                {
                     sb.Append(step);
                    sb.Append(j);
                }
        }

        if(sb.Length >= S.Length)
        {
            return S;
        }

        return sb.ToString();
    }
}
```