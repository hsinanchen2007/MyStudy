### 解题思路
        /* 将第一个字符串依次和其他字符串进行对比
         * 将集合strs中的第一个字符串strs[0]与其他字符串依次进行比较
         * 设strs[0]的长度为i
         * 设集合strs中有j+1个元素 
         * 返回结果为result,若不存在公共前缀则返回空
         * 当strs[0]的一个字节与其他字符串的第一个字节比较完的时候并相同时，result等于strs[0]的第一个字节
         * 
         * PS:需要考虑
         * 1.当strs为空的情况
         * 2.当strs[0]是集合strs中最长的字符串时
         */

### 代码

```csharp
public class Solution {
    public string LongestCommonPrefix(string[] strs) {
            if (strs.Length == 0)
            {
                return "";
            }
            string result = "";
            for (int i = 1; i <= strs[0].Length; i++)
            {
                for (int j = 1; j < strs.Length; j++)
                {
                    if (i> strs[j].Length || strs[0].Substring(0, i) != strs[j].Substring(0, i))
                    {
                        return result; ;
                    }

                }
                result = strs[0].Substring(0, i);
            }
            return result;
}
}
```