### 解题思路
寫完的時候很開心想說要打趴所有人，結果跑出時間竟然只有50%...
有人知道哪裡出了問題嗎...
### 代码

```csharp
public class Solution {
    public char FindTheDifference(string s, string t) {
        int ans = 0;
        foreach(char c in s+t)
            ans = c ^ ans;
        return (char)ans;
    }
}
```