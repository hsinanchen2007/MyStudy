可以将字母组合视为一个进制比较特别的数字。计算数字的范围，然后根据特殊进制规则，翻译结果。
比如：“23”是两位3进制(“a|b|c”“d|e|f”)的数字，值域为【0-8】共9个数字。
注意：位数较长时，有溢出风险。
可以用该思路将字符串映射到数字，如在数据库设计中以整型替代字符串作为主键，提高检索效率。

```

public class Solution {
    const char BaseChar = '2';
    static readonly string[] Phone = new string[] {"abc" ,"def" ,"ghi" ,"jkl" ,"mno" ,"pqrs","tuv" ,"wxyz"};

    public IList<string> LetterCombinations(string digits)
    {
        var digitArray = digits.ToCharArray();
        var wordsCount = digitArray.Length == 0 ? 0 : 1;
        var baseNum = new int[digitArray.Length];
        // for (int i = 0; i < digitArray.Length; i++)
        for (int i = digitArray.Length - 1; i >= 0; i--)
        {
            baseNum[i] = wordsCount;
            wordsCount *= Phone[digitArray[i] - BaseChar].Length;
        }
        var result = new List<string>(wordsCount);            
        var word = new char[digitArray.Length];
        for (int num = 0; num < wordsCount; num++)
        {
            for (int i = 0; i < digitArray.Length; i++)
            {
                var letters = Phone[digitArray[i] - BaseChar];
                word[i] = letters[num / baseNum[i] % letters.Length];
            }
            result.Add(new string(word));
        }
        return result;
    }
}

```