### 解题思路
执行用时 :108 ms, 在所有 csharp 提交中击败了73.77%的用户
内存消耗 :25 MB, 在所有 csharp 提交中击败了5.69%的用户
将所有可能构建规则字典，循环每个字符利用Substring截取字符串字典匹配，解法简单明了。
### 代码

```csharp
public class Solution {
    public int RomanToInt(string s) {
        var dc = new Dictionary<string,int>();
        dc.Add("I",1);
        dc.Add("IV",4);
        dc.Add("IX",9);
        dc.Add("V",5);
        dc.Add("X",10);
        dc.Add("XL",40);
        dc.Add("XC",90);
        dc.Add("L",50);
        dc.Add("C", 100);
        dc.Add("CD", 400);
        dc.Add("CM", 900);
        dc.Add("D", 500);
        dc.Add("M", 1000);
        var sum = 0;
        for(var i = 0;i < s.Length;)
        {
            if(i + 2 <= s.Length 
             && dc.ContainsKey(s.Substring(i,2)))
             {
                 sum += dc[s.Substring(i,2)];
                 i += 2;
             } else {
                 sum += dc[s.Substring(i,1)];
                 i ++;
             }
        }
        return sum;
    }
}
```