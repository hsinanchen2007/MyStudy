```csharp
public string ReverseWords(string s) {
    StringBuilder sb = null;
    Stack<string> st = new Stack<string>();
    for(int i = 0; i < s.Length; i++)
    {
        if(s[i] != ' ')
        {
            if(sb == null)
            {
                sb = new StringBuilder();
            }
            sb.Append(s[i]);
        }
        else
        {
            if(sb != null && sb.Length > 0)
            {
                st.Push(sb.ToString());
                sb = null;
            }
        }
    }
    if(sb != null && sb.Length > 0)
    {
        st.Push(sb.ToString());
    }
    sb = new StringBuilder();
    if(st.Count > 0)
    {
        while(true)
        {
            sb.Append(st.Pop());
            if(st.Count > 0)
            {
                sb.Append(" ");
            }
            else
            {
                break;
            }
        }
    }
    return sb.ToString();
}
```