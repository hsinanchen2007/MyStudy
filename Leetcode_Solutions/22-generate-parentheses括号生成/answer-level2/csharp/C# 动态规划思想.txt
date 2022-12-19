**类似于动态规划的思想**
题目求n对括号的所有有效串，
那我们就先找出n-1对括号的有效串，
再往里插入字符串"()",
最后再去重。
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        
    List<string> result = new List<string>();
            result.Add("()");
            if (n == 1)
            {
          
                return result;
            }
            for (int i = 1; i < n; i++)
            {
                List<string> temp = new List<string>();
                for (int j = 0; j <result.Count;j++)
                {
                    string s = result[j];
                    for (int k = 0; k <= s.Length; k++)
                    {
                        temp.Add(s.Insert(k,"()"));
                    }
                }
                result = temp.Distinct().ToList();
            }

            return result;
    }
}