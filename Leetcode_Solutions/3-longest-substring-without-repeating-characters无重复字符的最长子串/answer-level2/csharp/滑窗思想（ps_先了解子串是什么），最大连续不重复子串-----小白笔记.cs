### 解题思路
按照大神的指引，利用滑窗的思想进行题目的解析。
要点：
     1.连续子串
     2.键值对
     3.滑窗边界
思想：1.循环遍历字符串，将字符，对应索引储存在字典中.
      2.当遍历到重复字符时，获取字典中重复字符的索引位置，
        与上一次对应的滑窗左边界位置进行比对，取其中的最大值作为左边界.
      3.计算当前子串的长度，与上一次的子串长度比对，获取最大值，得到最大连续子串长度.

### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string str) {
            Dictionary<char, int> dict = new Dictionary<char, int>();
            int maxLen = 0;
            
            //start：左边界，end：右边界
            for (int end = 0, start = 0; end < str.Length; end++)
            {
                if (dict.ContainsKey(str[end]))
                {
                     //重置开始索引，获得滑动窗口左边框值（左边界）
                     start = Math.Max(dict[str[end]]+1, start);   
                }
                 maxLen = Math.Max(end - start+1, maxLen);
                //更新对应字符的索引位置 
                dict[str[end]]=end;
            }
            return maxLen;
    }
}
```