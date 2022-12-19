### 解题思路

##### 1. 题目概述：反转字符串

##### 2. 思路：
   - 特征：每 2k 个字符的处理方式是一样的,可以考虑循环;针对前 k 个字符的反转,考虑使用双指针的方式;起始位置还好,中止位置要避免越界;
   - 方案：最外层是一个循环,步长为 2k;内存是一个 while 循环,负责对前 k 个字符做反转;因为字符串的特殊性,这里将其转换为字符数组来处理了;
   - 结果：循环完以后,得到的字符串

##### 3. 知识点：双指针 字符串

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public string ReverseStr(string s, int k)
        {
            var strArray = s.ToCharArray();
            for (var i = 0; i < s.Length; i += 2 * k)
            {
                var leftIndex = i;
                var rightIndex = Math.Min(i + k - 1, s.Length - 1);
                while (leftIndex < rightIndex)
                {
                    var temp = strArray[leftIndex];
                    strArray[leftIndex++] = strArray[rightIndex];
                    strArray[rightIndex--] = temp;
                }
            }

            return new string(strArray);
        }
}
```