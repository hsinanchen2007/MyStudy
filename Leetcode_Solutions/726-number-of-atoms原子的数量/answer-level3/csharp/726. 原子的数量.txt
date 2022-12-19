### 解题思路
使用字典和队列模拟统计；
使用递归处理括号；

### 代码

```csharp
public class Solution {
    public string CountOfAtoms(string formula)
    {
        if (string.IsNullOrWhiteSpace(formula)) return string.Empty;
        var queue = new Queue<char>(formula);
        var result = GetCountOfAtoms(queue);
        var builder = new StringBuilder(result.Count * 4);
        foreach (var atom in result.Keys.OrderBy(key => key))
        {
            builder.Append($"{atom}{(result[atom] > 1 ? result[atom].ToString() : string.Empty)}");
        }
        return builder.ToString();
    }

    public Dictionary<string, int> GetCountOfAtoms(Queue<char> formula)
    {
        var result = new Dictionary<string, int>();
        if (formula.Count == 0) return result;

        var atomBuilder = new StringBuilder();
        var countBuilder = new StringBuilder();
        while (formula.Count > 0)
        {
            var @char = formula.Dequeue();
            if (char.IsUpper(@char))
            {
                RecordAtomCount(result, atomBuilder, countBuilder);
                atomBuilder.Append(@char);
            }
            else if (char.IsLower(@char))
            {
                atomBuilder.Append(@char);
            }
            else if (char.IsDigit(@char))
            {
                countBuilder.Append(@char);
            }
            else if (@char == '(')
            {
                RecordAtomCount(result, atomBuilder, countBuilder);
                var subResult = GetCountOfAtoms(formula);
                CombineAtomCounts(result, subResult);
            }
            else if (@char == ')')
            {
                RecordAtomCount(result, atomBuilder, countBuilder);
                while (formula.Count > 0)
                {
                    if (char.IsDigit(formula.Peek()))
                    {
                        countBuilder.Append(formula.Dequeue());
                    }
                    else
                    {
                        break;
                    }
                }
                MultiplyAtomCount(result, countBuilder);
                return result;
            }
        }

        RecordAtomCount(result, atomBuilder, countBuilder);

        return result;
    }

    private void RecordAtomCount(
        Dictionary<string, int> result,
        StringBuilder atomBuilder,
        StringBuilder countBuilder)
    {
        if (atomBuilder.Length > 0)
        {
            var atom = atomBuilder.ToString();
            var count = countBuilder.Length > 0 ? int.Parse(countBuilder.ToString()) : 1;
            atomBuilder.Clear();
            countBuilder.Clear();
            if (result.ContainsKey(atom))
            {
                result[atom] += count;
            }
            else
            {
                result[atom] = count;
            }
        }
    }

    private void CombineAtomCounts(Dictionary<string, int> target, Dictionary<string, int> source)
    {
        foreach (var key in source.Keys)
        {
            if (target.ContainsKey(key))
            {
                target[key] += source[key];
            }
            else
            {
                target[key] = source[key];
            }
        }
    }

    private void MultiplyAtomCount(Dictionary<string, int> result, StringBuilder countBuilder)
    {
        if (countBuilder.Length > 0)
        {
            var times = int.Parse(countBuilder.ToString());
            var keys = result.Keys.ToArray();
            foreach (var key in keys)
            {
                result[key] *= times;
            }
        }
    }
}
```