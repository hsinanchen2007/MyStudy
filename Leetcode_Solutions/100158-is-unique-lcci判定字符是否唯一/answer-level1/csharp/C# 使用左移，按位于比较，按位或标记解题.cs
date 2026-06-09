### 代码

```csharp
public class Solution {
    public bool IsUnique(string astr)
    {
        int mark = 0, t;

        for (int i = 0; i < astr.Length; i++)
        {
            // 指定字符到字符a（97）的偏移量
            t = astr[i] - 'a';
            if ((mark & (1 << t)) != 0) { return false; }

            mark |= (1 << t);
        }

        return true;
    }
}
```