### 解题思路
主体思路等同官方思路3滑动窗口，MARK一个细节。
    假设start指向sArray[3],此时sArray[0]-sArray[2]的元素已经存在于dic中，但是在判断是否重复时，这部分元素不应被包括进去。
    代码实现：
        if (dic[chr] >= start)
        {
            start = dic[chr] + 1;
        }

            dic[chr] = i;

### 代码

```csharp
public class Solution {
    public int LengthOfLongestSubstring(string s) {
            var sArray = s.ToCharArray();
            var maxLen = 0;
            var start = 0;
            Dictionary<char, int> dic = new Dictionary<char, int>();
            for(var i = 0; i < sArray.Length; i ++)
            {
                var chr = sArray[i];
                if (dic.ContainsKey(chr))
                {
                    if (dic[chr] >= start)
                    {
                        start = dic[chr] + 1;
                    }

                        dic[chr] = i;
                }
                else
                {
                    dic.Add(chr, i);
                }
                
                maxLen = Math.Max(maxLen, i - start + 1);

            }
            return maxLen;
    }
}
```