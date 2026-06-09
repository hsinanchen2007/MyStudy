```
public class Solution {
    public string ReverseLeftWords(string s, int n) {
        string s1 =s.Substring(0,n);
        s = s.Remove(0,n);
        return s+s1;
    }
}
```
