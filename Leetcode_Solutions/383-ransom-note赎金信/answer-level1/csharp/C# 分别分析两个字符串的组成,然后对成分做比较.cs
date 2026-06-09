### 解题思路

##### 1. 题目概述：赎金信

##### 2. 思路：
   - 特征：源字符串提供的字符,是否能够足额提供给目标字符串
   - 方案：是否足够,显然是要做统计的,分别分析源字符串和目标字符串,然后比较各个字母是否足够使用,因为字符串是有小写字母构成,所以直接使用了一个容量足够的数组来表示了
   - 结果：将统计结果做对比,如果源字符串提供的字符不足,则 false

##### 3. 知识点：字典 数组

##### 4. 复杂度分析: 
   - 时间复杂度：O(m+n) 表示两个字符串的长度
   - 空间复杂度：O(1) 分析结果使用的数组大小是恒定的


### 代码

```csharp []
public class Solution {
        public bool CanConstruct(string ransomNote, string magazine)
        {
            var targetArray = AnalyzedStr(ransomNote);
            var sourceArray = AnalyzedStr(magazine);

            for(var i = 0;i < targetArray.Length; i++)
                if (targetArray[i] > sourceArray[i])
                    return false;

            return true;
        }

        private int[] AnalyzedStr(string str)
        {
            var forReturn = new int[26];
            foreach (var strItem in str)
                forReturn[strItem - 'a']++;

            return forReturn;
        }
}
```