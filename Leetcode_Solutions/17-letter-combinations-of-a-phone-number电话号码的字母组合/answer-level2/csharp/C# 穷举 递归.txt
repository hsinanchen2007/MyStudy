### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public Dictionary<char, char[]> dic = new Dictionary<char, char[]>()
    {
        {'2', new char[]{'a', 'b', 'c'}},
        {'3', new char[]{'d', 'e', 'f'}},
        {'4', new char[]{'g', 'h', 'i'}},
        {'5', new char[]{'j', 'k', 'l'}},
        {'6', new char[]{'m', 'n', 'o'}},
        {'7', new char[]{'p', 'q', 'r', 's'}},
        {'8', new char[]{'t', 'u', 'v'}},
        {'9', new char[]{'w', 'x', 'y', 'z'}} 
    };
    
    //穷举法
    public IList<string> LetterCombinations1(string digits) 
    {
        try
        {          
            List<string> l1 = dic[digits[0]].Select(a => a.ToString()).ToList();
            List<string> l2 = new List<string>();
            bool curL1 = true; //true：使用l1，false：使用l2
            for(int i = 1; i < digits.Length; i++)
            {
                List<string> source, target;
                if(curL1) //两个列表交替使用
                {
                    source = l1;
                    target = l2;
                }
                else
                {
                    source = l2;
                    target = l1;
                }
                for(int j = 0; j < source.Count; j++)
                {
                    foreach(char c in dic[digits[i]])
                    {
                        target.Add(source[j] + c);
                    }
                }
                source.Clear();
                curL1 = !curL1; //切换列表
            }
            if(curL1)
            {
                return l1;
            }
            else
            {
                return l2;
            }
        }
        catch
        {
            return new List<string>();
        }
    }

    //递归法
    public IList<string> LetterCombinations2(string digits)
    {
        try
        {          
            if(digits.Length == 1)
            {
                return dic[digits[0]].Select(a => a.ToString()).ToList();
            }
            else
            {
                //每次递归截去最后一个字符
                IList<string> list 
                    = LetterCombinations2(digits.Substring(0, digits.Length - 1));
                List<string> ans = new List<string>();
                foreach(string str in list)
                {
                    foreach(char c in dic[digits[digits.Length - 1]])
                    {
                        ans.Add(str + c);
                    }
                }
                return ans;
            }
        }
        catch
        {
            return new List<string>();
        }
    }
}
```