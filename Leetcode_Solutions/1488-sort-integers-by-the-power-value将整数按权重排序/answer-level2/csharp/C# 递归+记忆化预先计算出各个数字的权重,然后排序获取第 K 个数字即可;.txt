### 解题思路

##### 1. 题目概述：将整数按照权重来排序

##### 2. 思路：
   - 特征：若为偶数,数字会减小;若为奇数,数字会变大;如果要变到 1,只能从偶数变过来,也就是减小的操作;其实各个数字的变化,路径会有重叠,若能做记忆化,可提升速度;
   - 方案：预先计算出 1000 个数的权重;其中使用了递归和记忆化的方式;然后将给定范围的数与权重建立关联;最后先按照权重排序,再按照数字大小排序,得到第 k 个数
   - 结果：排序后数组中的第 k 个数

##### 3. 知识点：递归

##### 4. 复杂度分析: 
   - 时间复杂度：O(n)
   - 空间复杂度：O(1)


### 代码

```csharp []
public class Solution {
        public int GetKth(int lo, int hi, int k)
        {
            if (m_innerNumStepsDic == null)
            {
                m_innerNumStepsDic = new Dictionary<int, int>(2000) { { 1, 0 } };
                for (var i = 2; i <= 1000; i++)
                    Recursive(i);
            }

            var numArray = new int[hi - lo + 1][];
            for (var i = 0; i < numArray.Length; i++)
                numArray[i] = new[] { i + lo, m_innerNumStepsDic[i + lo] };

            return numArray.OrderBy(i => i[1]).ThenBy(i => i[0]).Skip(k - 1).First()[0];
        }

        private static Dictionary<int, int> m_innerNumStepsDic;

        private int Recursive(int i)
        {
            if (m_innerNumStepsDic.ContainsKey(i))
                return m_innerNumStepsDic[i];

            var num = 0;
            if ((i & 1) == 1)
                num = Recursive(i * 3 + 1);
            else
                num = Recursive(i / 2);

            m_innerNumStepsDic[i] = num + 1;
            return m_innerNumStepsDic[i];
        }
}
```