

### 代码

```csharp
public class Solution {
    public bool IsSubsequence(String s, String t)
        {
            int currentIndex = 0;
            for (int i = 0; i < s.Length; i++)
            {
                bool exist = false;
                for (int j = currentIndex; j < t.Length; j++)
                {
                    if (t[j] == s[i])
                    {
                        currentIndex = j + 1;
                        exist = true;
                        break;
                    }
                }
                if (exist == false)
                {
                    return false;
                }
            }

            return true;
        }
}
```