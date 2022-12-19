### 解题思路

##### 1. 题目概述：字符串中的单词数

##### 2. 思路：
   - 特征：就是要数非空格的连续区域有多少个,只要能把空格的位置标记出来,那么中间的部分,就是单词区域了
   - 方案：遍历字符串,依次定位空格的位置,若与上一次空格出现位置的间距大于 1,那么它俩中间就一定有单词了
   - 结果：注意边界的考量,总之,一边定位空格,一边做统计,得到的结果就是解

##### 3. 知识点：字符串

##### 4. 复杂度分析: n是字符串的长度
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int CountSegments(string s)
        {
            var forReturn = 0;
            var preIndex = -1;
            for (var i = 0; i < s.Length; i++)
            {
                var curChar = s[i];
                if (curChar != ' ') continue;

                if (i - preIndex > 1)
                    forReturn++;

                preIndex = i;
            }

            if (preIndex != s.Length - 1)
                forReturn++;

            return forReturn;
        }

        public int CountSegments(string s) => s.Split(' ', StringSplitOptions.RemoveEmptyEntries).Length;
}
```