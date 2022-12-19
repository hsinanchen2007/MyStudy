### 解题思路
以startPos = 0; 作为不重复最长候选子串的开始位置
从0下标开始遍历
    如果当前字符之前没出现过，记录这个字符的位置到charPos的dictionary里,否则
    当前字符之前出现过
        当前字符和之前出现过的位置之间有一个最大不重复子串候选
        找到之前的位置的下一个字符作为以startPos


### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> charPos = new Dictionary<char, int>();

        int m = 0;
        int startPos = 0;
        int end = 0;
        for(int i = 0; i < s.Length; i++)
        {
            int oldPos = -1;
            if(charPos.TryGetValue(s[i], out oldPos))
            {
                if(end - startPos > m)
                {
                    m = end - startPos;
                }

                for(int j = startPos; j < oldPos; j++)
                {
                    charPos.Remove(s[j]);
                }
                
                startPos = oldPos + 1;

                charPos[s[i]] = i;
            }
            else
            {
                charPos.Add(s[i], i);
            }
            
            end = i + 1;
        }

        if(end - startPos > m)
        {
            m = end - startPos;
        }

        return m;
    }
}

```