
```
public class Solution 
{
    public string ToLowerCase(string str) 
    {
        var chars = str.ToCharArray();
        var sb = new StringBuilder();
        var temp = (char)32;
        for (int i = 0; i < chars.Length; i++)
        {
            if (chars[i] > 64 && chars[i] < 91)
            {
                chars[i] += temp;
            }
            sb.Append(chars[i]);
        }
        return sb.ToString();
    }
}
```
