### 解题思路
设numCounts[i]为[0, i]范围内子数组的数字总个数
设letterCounts[i]为[0, i]范围内子数组的子母总个数
设满足题意的子数组的位置在[startPos, endPos]的闭区间
那么这个子数组一定满总下面的条件
    numCounts[startPos - 1] - letterCounts[startPos - 1] == numCounts[endPos] - letterCounts[endPos]

所以把numCounts[i] - letterCounts[i]的差值的最大位置和最小位置保存到两个字典里后， 遍历两个字典就可以找到最长子数组



### 代码

```csharp
public class Solution {
    bool isNum(char c)
    {
        return '0' <= c && c <= '9';
    }

    public string[] FindLongestSubarray(string[] array) {
        int[] numCounts = new int[array.Length];
        int[] letterCounts = new int[array.Length];

        int numCount = 0;
        int letterCount = 0;
        for(int i = 0; i < array.Length; i++)
        {
            if(isNum(array[i][0]))
            {
                numCount++;
            }
            else
            {
                letterCount++;
            }

            numCounts[i] = numCount;
            letterCounts[i] = letterCount;
        }

        int[] dCount = new int[array.Length + 1];
        dCount[0] = 0;
        for(int i = 0; i < array.Length; i++)
        {
            dCount[i + 1] = numCounts[i] - letterCounts[i];
        }

        
        Dictionary<int, int> dStartPosMap = new Dictionary<int, int>();
        Dictionary<int, int> dEndPosMap = new Dictionary<int, int>();
        for(int i = 0; i < dCount.Length; i++)
        {
            if(!dStartPosMap.ContainsKey(dCount[i]))
            {
                dStartPosMap.Add(dCount[i], i);
            }

            if(!dEndPosMap.ContainsKey(dCount[dCount.Length - 1 - i]))
            {
                dEndPosMap.Add(dCount[dCount.Length - 1 - i], dCount.Length - 1 - i);
            }
        }

        int startIndex = 0;
        int endIndex = 0;
        int m = 0;
        foreach(var entry in dStartPosMap)
        {
            int startPos = entry.Value;
            int endPos = dEndPosMap[entry.Key] - 1;

            if(endPos - startPos > m)
            {
                startIndex = startPos;
                endIndex = endPos;
                m = endPos - startPos;
            }
            else if(endPos - startPos == m)
            {
                if(startPos < startIndex)
                {
                    startIndex = startPos;
                    endIndex = endPos;
                    m = endPos - startPos;
                }
            }
        }

        if(m <= 0)
        {
            return new string[0];
        }

        string[] ret = new string[endIndex - startIndex + 1];
        for(int i = startIndex; i <= endIndex; i++)
        {
            ret[i - startIndex] = array[i];
        }
        return ret;
    }
}
```