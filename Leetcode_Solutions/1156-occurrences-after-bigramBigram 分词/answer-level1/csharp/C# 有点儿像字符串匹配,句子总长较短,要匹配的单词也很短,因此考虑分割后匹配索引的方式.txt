```C# []
        public string[] FindOcurrences(string text, string first, string second)
        {
            /*
             * 题目概述：分词
             * 
             * 思路：
             *  1.在给定的字符串文本中匹配出特定模式的文本
             *  2.字符串文本是由单词构成的,单词之间有空格,因此可以考虑分割成字符串数组
             *  3.然后在字符串数组中,依次去做匹配
             *  4.最外层的遍历范围要少 2 个索引
             *
             * 关键点：数组
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(n)
             */

            var forReturn = new List<string>();

            var textArray = text.Split(' ');
            for (var i = 0; i < textArray.Length - 2; i++)
            {
                if (textArray[i] != first || textArray[i + 1] != second) continue;

                forReturn.Add(textArray[i + 2]);
            }

            return forReturn.ToArray();
        }
```
