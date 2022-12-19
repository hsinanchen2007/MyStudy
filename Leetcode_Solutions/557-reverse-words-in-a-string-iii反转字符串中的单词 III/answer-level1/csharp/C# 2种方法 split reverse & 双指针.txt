### 解题思路

##### 1. 题目概述：反转字符串中的单词

##### 2. 思路：
   - 特征：需要确认单词的范围;然后再反转;
   - 方案：外层循环确定每个单词的起始位置;内层循环确定单词的末尾位置;
   - 结果：两重循环处理后的结果;

##### 3. 知识点：字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(n)


### 代码

```csharp解一 []
public class Solution {
        public string ReverseWords1(string s)
        {
            var cArray = s.ToCharArray();
            for (var i = 0; i < s.Length;)
            {
                var startIndex = i;
                var endIndex = s.IndexOf(' ', i);
                if (endIndex == -1)
                    endIndex = s.Length - 1;
                else
                    endIndex--;

                i = endIndex + 2;

                while (startIndex < endIndex)
                {
                    var temp = cArray[startIndex];
                    cArray[startIndex++] = cArray[endIndex];
                    cArray[endIndex--] = temp;
                }
            }

            return new string(cArray);
        }
}
```
```csharp解二 []
public class Solution {
        public string ReverseWords(string s)
        {
            return string.Join(" ", s.Split(' ').Select(i => new string(i.Reverse().ToArray())));
        }
}
```