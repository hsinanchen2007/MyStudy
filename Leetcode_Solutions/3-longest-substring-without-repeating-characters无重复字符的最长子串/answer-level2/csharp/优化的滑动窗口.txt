### 解题思路
看了官方的解题思路，比较好理解。最后卡在了如何计算子串长度上，刚开始是在分别讨论时计算长度并且在每一次有重复时才计算长度，这会导致一些测试用例失败，例如只有一个字符的时候。后来改成统一计算长度，并且每一次都更新最大长度：1. 进行统一地抽象，避免了分类讨论引入的复杂性；2. 避免有些测试用例失败，例如，"", " ". 另外，在字符串处理中，滑动窗口这种算法经常使用，值得细致研究下进而举一反三。

### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int i = 0, j = 0;
        Dictionary<int, int> indexDictionary = new Dictionary<int, int>();

        while(i < s.Length){
            if(!indexDictionary.ContainsKey(s[i])){
                indexDictionary.Add(s[i],i);
            }
            else{
                j=Math.Max(indexDictionary[s[i]] + 1, j);
                indexDictionary[s[i]]=i;
            }

            i++;
            maxLength=Math.Max(i - j, maxLength);
        }

        return maxLength;
    }
}
```