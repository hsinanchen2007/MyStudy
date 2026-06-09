### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool AreSentencesSimilar(string[] words1, string[] words2, IList<IList<string>> pairs) {
            if (words1.Length != words2.Length)
            {
                return false;
            }

            List<string> _list = new List<string>();
            foreach (IList<string> _item in pairs)
            {
                _list.Add(_item[0] + "&" + _item[1]);
            }

            for (int i = 0; i < words1.Length; i++)
            {
                if (words1[i] != words2[i] && !_list.Contains(words1[i] + "&" + words2[i]) && !_list.Contains(words2[i] + "&" + words1[i]))
                {
                    return false;
                }
            }
            return true;
    }
}
```