
```
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```
链接：[https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/)

```C#
public class Solution {    
    List<string> res = new List<string>();    
    public IList<string> LetterCombinations(string digits) 
    {         
        if (string.IsNullOrWhiteSpace(digits)) return res;
        Dictionary<char, string> map = new Dictionary<char, string>()
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        _LetterCombinations(digits, String.Empty, map, 0);

        return res;
    }
    private void _LetterCombinations(string digits, string log, Dictionary<char, string> map, int level)
    {
        //排列组合->回溯->回溯模板=》_,_,_
        if (log.Length == digits.Length) //terminator
        {
            res.Add(log);
            return;
        }

        string str = map[digits[level]]; //当前层选择列表
        for (int i = 0; i < str.Length; i++) //遍历列表
        {
            log = log + str[i]; //进行选择
            _LetterCombinations(digits, log, map, level + 1); //drill down
            log = log.Remove(log.Length - 1); //恢复当前状态
        }
        //reverse
    }
}
```