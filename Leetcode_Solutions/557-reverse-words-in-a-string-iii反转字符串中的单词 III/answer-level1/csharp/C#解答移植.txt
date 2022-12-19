
```csharp
public string ReverseWords(string s)
{
    StringBuilder a = new StringBuilder(s);
    int front = 0;
    for (int i = 0; i < s.Length; i++)
    {
        if (s[i] == ' ')
        {
            ReverseString(front, i - 1, a);
            front = i + 1;
        }
    }
    ReverseString(front, s.Length - 1, a);
    return a.ToString();
}
public void ReverseString(int front, int tail, StringBuilder str)
{
    while (front < tail)
    {
        str[front] ^= str[tail];
        str[tail] ^= str[front];
        str[front++] ^= str[tail--];
    }
}
```
![image.png](https://pic.leetcode-cn.com/06f675afdf187b4c33de1b0f484ac8f742c359ffcab3e913fcbfc7655b1aa5db-image.png)

