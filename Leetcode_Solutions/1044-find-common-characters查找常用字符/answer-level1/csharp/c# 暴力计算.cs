### 解题思路
遍历数组，形成字典集合，记录每个字符串中每个字符出现的字数。
同时使用HashSet记录下最终需要匹配的字符集合。（取第一个字符串的每一个字符）
挨个字符匹配，返回最小值，最小值就是需要输出的次数。

### 代码

```csharp
public class Solution {
    public IList<string> CommonChars(string[] A) {
        List<Dictionary<char, int>> temp = new List<Dictionary<char, int>>();
            HashSet<char> first = new HashSet<char>();
            for (int i = 0; i < A.Length; i++)
            {
                Dictionary<char, int> current = new Dictionary<char, int>();
                foreach (var item in A[i])
                {
                    if (current.ContainsKey(item))
                    {
                        current[item] = current[item] + 1;
                    }
                    else
                    {
                        current.Add(item, 1);
                    }
                    first.Add(item);
                }
                temp.Add(current);
            }

            List<string> result = new List<string>();

            foreach (var item in first)
            {
                int? min = null;
                foreach (var jtem in temp)
                {
                    if (jtem.ContainsKey(item))
                    {
                        if (!min.HasValue)
                        {
                            min = jtem[item];
                        }
                        else
                        {
                            min = min > jtem[item] ? jtem[item] : min;
                        }
                    }
                    else
                    {
                        min = 0;
                        break;
                    }
                }

                if (min > 0)
                {
                    for (int i = 0; i < min; i++)
                    {
                        result.Add(item.ToString());
                    }
                }

            }

        return result;
    }
}

```