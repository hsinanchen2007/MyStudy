### 解题思路

##### 1. 题目概述：合并排序的数组

##### 2. 思路：
   - 特征：已知两个数组是有序的,但是并没有说是顺序还是逆序(这个要自己判断了);已知 A 数组更长,那么显然 A 就是用来存储最后合并结果的
   - 方案：使用 3 个索引分别标识 数组 A 的最后一个元素,数组 B 的最后一个元素,合并数组的最后一个元素,依据顺序关系依次填充,判断顺序,就是依次比较数组中相邻的 2 个元素,默认是顺序的,一旦发现逆序,那么就一定是逆序了
   - 结果：最后 A 数组中存储的,就是期望中的结果了

##### 3. 知识点：数组

##### 4. 复杂度分析: 
   - 时间复杂度：O(n + m)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public void Merge(int[] A, int m, int[] B, int n)
        {
            var isSmallToBigger = JudgeSmallToBiggerResult(A, m, B, n);
            Opera(A, m, B, n, isSmallToBigger);
        }

        private void Opera(int[] A, int m, int[] B, int n, bool isSmallToBigger)
        {
            Func<int, int, bool> FuncSToBigger = (a, b) => a >= b;
            Func<int, int, bool> FuncBToSmall = (a, b) => a <= b;

            var Func = isSmallToBigger ? FuncSToBigger : FuncBToSmall;

            var writeIndex = A.Length - 1;
            var aIndex = m - 1;
            var bIndex = n - 1;

            while (aIndex >= 0 && bIndex >= 0)
            {
                var aValue = A[aIndex];
                var bValue = B[bIndex];

                var valueTemp = 0;
                if (Func(aValue, bValue))
                {
                    aIndex--;
                    valueTemp = aValue;
                }
                else
                {
                    bIndex--;
                    valueTemp = bValue;
                }

                A[writeIndex--] = valueTemp;
            }

            while (aIndex >= 0)
                A[writeIndex--] = A[aIndex--];

            while (bIndex >= 0)
                A[writeIndex--] = B[bIndex--];
        }

        private bool JudgeSmallToBiggerResult(int[] A, int m, int[] B, int n)
        {
            var result1 = IsSmallToBiggerArray(A, m);
            var result2 = IsSmallToBiggerArray(B, n);
            if (!result1 || !result2)
                return false;

            return true;
        }

        private bool IsSmallToBiggerArray(int[] array, int count)
        {
            for (var i = 0; i < count - 1; i++)
                if (array[i] > array[i + 1]) return false;

            return true;
        }
}
```