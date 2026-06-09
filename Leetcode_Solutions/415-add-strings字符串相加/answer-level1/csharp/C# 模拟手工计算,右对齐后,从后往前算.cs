### 解题思路

##### 1. 题目概述：字符串相加

##### 2. 思路：
   - 特征：其实也就是大数相加了
   - 方案：模拟手算相加的方式,先让各位对齐,然后其它位也对齐,按位相加.两个数的加和要么和最长的数字一样长,要么就是比最长的数字多 1 位
   - 结果：模拟完成以后,得到了字符数组,就是两个字符串的加和结果

##### 3. 知识点：数组

##### 4. 复杂度分析: m 表示 num1 的长度,n 表示 num2 的长度
   - 时间复杂度：O(max(m,n))
   - 空间复杂度：O(max(m,n))


### 代码

```csharp []
public class Solution {
        public string AddStrings(string num1, string num2)
        {
            var numArray = GetNumArray();
            var forReturnArray = new char[Math.Max(num1.Length, num2.Length) + 1];
            var oneIndex = num1.Length - 1;
            var twoIndex = num2.Length - 1;
            var arrayIndex = forReturnArray.Length - 1;
            var initNum = 0;
            while (oneIndex >= 0 || twoIndex >= 0)
            {
                var oneNum = 0;
                if (oneIndex >= 0)
                    oneNum = num1[oneIndex--] - '0';

                var twoNum = 0;
                if (twoIndex >= 0)
                    twoNum = num2[twoIndex--] - '0';

                var sumTemp = initNum + oneNum + twoNum;
                forReturnArray[arrayIndex--] = numArray[sumTemp % 10];
                initNum = sumTemp / 10;
            }

            if (initNum > 0)
            {
                forReturnArray[arrayIndex] = numArray[initNum];
                return new string(forReturnArray);
            }

            return new string(forReturnArray.Skip(1).ToArray());
        }

        private char[] GetNumArray()
        {
            var numArray = new char[10];
            for (var i = '0'; i <= '9'; i++)
                numArray[i - '0'] = i;

            return numArray;
        }
}
```