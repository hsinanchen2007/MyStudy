### 解题思路
没有用活动窗口，而是采用一次遍历的方法，给各位分享一下。

使用dicT<char, List<int>>记录各个字符出现的次数。

其中 char: char in t, List<int>{char count, location 1, location 2, ... }

示例：
{'a', {1,5,9}}
{'b', {2,1,10,17,20}}
{'c', {1,22}}

假设此时i=22, 即S[22] = 'C'， 那么以22为尾部，最小字符串的头部fullhead = min(9, 17) = 9

### 代码

```csharp
public class Solution {
    public string MinWindow(string s, string t) {
                    //dicT<char, List<int>>, char: char in t, List<int>{char count, location 1, location 2, ... }
            Dictionary<char, List<int>> dicT = new Dictionary<char, List<int>>();
            string res = s + "end";

            for (var i = 0; i < t.Length; i++)
            {
                if (!dicT.ContainsKey(t[i]))
                    dicT.Add(t[i], new List<int>() { 1 });
                else
                    dicT[t[i]][0] += 1;
            }
               

            for(var j = 0; j < s.Length; j++)
            {
                if(dicT.ContainsKey(s[j]))
                {
                    dicT[s[j]].Add(j);

                    var fullhead = j;
                    foreach (var item in dicT)
                    {
                        if (item.Value.Count() <= item.Value[0])
                        {
                            fullhead = -1;
                            break;
                        }
                        else
                            fullhead = Math.Min(item.Value[item.Value.Count() - item.Value[0]], fullhead);
                    } 
                              
                    if (fullhead != -1 && res.Length > j - fullhead + 1)
                        res = s.Substring(fullhead, j - fullhead + 1);
                }
            }

            if (res.Length <= s.Length)
                return res;
            else
                return "";
    }
}
```