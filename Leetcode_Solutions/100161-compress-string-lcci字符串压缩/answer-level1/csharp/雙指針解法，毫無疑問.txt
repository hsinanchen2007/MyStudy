### 解题思路  
  AC之後，看了看時間怎麼久到天荒地老，還以為是自己想法不對，看了一下時間最短的，沒想到一模一樣==
測了一下StringBuilder，結果還真的比較快...學習了...

### 代码

```csharp
public class Solution {
    public string CompressString(string S) {
        if(S.Length == 0) return S;
        int cnt = 1;
        StringBuilder s = new StringBuilder();
        s.Append(S[0]);
        for(int i=1;i<S.Length;++i)
        {
            if(S[i-1]==S[i])
                cnt++;
            else
            {
                s.Append(cnt);
                s.Append(S[i]);
                cnt=1;
            }
        }
        s.Append(cnt);
        return s.Length < S.Length ? s.ToString() : S;


        /*
        if(string.IsNullOrWhiteSpace(S)){return S;}
        int cnt = 1;
        string res = S[0].ToString();
        for(int i=1;i<S.Length;++i)
        {
            if(S[i-1]==S[i])
                cnt++;
            else
            {
                res+=cnt;
                res+=S[i];
                cnt=1;
            }
        }
        res+=cnt;
        return res.Length >= S.Length ? S : res;
        */
    }
}
```