### 解题思路

##### 1. 题目概述：压缩字符串

##### 2. 思路：
   - 特征：给定的是一个字符数组,当字符连续出现时,可以修改成字符加一个统计值的形式,连续出现才有压缩的必要,因此这是一个检测字符是否连续出现的问题
   - 方案：两个指针,一个指向字符第一次出现的位置,另一个指向字符最后出现位置的后一个位置,它俩的距离超过 2 时,就考虑压缩输出
   - 结果：两个指针走过一轮以后,输出的就是压缩后的结果了

##### 3. 知识点：双指针

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int Compress(char[] chars)
        {
            var firstIndex = 0;
            var i = 1;
            var w = 0;
            for (; i < chars.Length; i++)
            {
                if (chars[i] == chars[firstIndex]) continue;

                ChangeChars(chars, ref w, i, firstIndex);
                firstIndex = i;
            }

            ChangeChars(chars, ref w, i, firstIndex);
            return w;
        }

        private void ChangeChars(char[] chars, ref int w, int i, int firstIndex)
        {
            chars[w++] = chars[firstIndex];
            if (i - firstIndex > 1)
            {
                var str = (i - firstIndex).ToString();
                for (var j = 0; j < str.Length; j++)
                    chars[w++] = str[j];
            }
        }
}
```