### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
        public IList<int> LuckyNumbers(int[][] matrix)
        {
            if(matrix.Length == 0)
                return null;
            IList<int> list = new List<int>();
            //遍历行 找出所有最小值 
            int[] k = GetRowMin(matrix);
            //遍历列 找出所有最大值
            int[] m = GetColMax(matrix);
            //对比两个数组是否有一样的
            list = m.Intersect(k).ToArray();
            return list;
        }

        //遍历行 找出所有最小值 
        public int[] GetRowMin(int[][] matrix)
        {
            List<int> minArray = new List<int>();
            for (int i = 0; i < matrix.GetLength(0); i++)//获取行数
            {
                int min = matrix[i][0];
                for (int j = 0; j < matrix[0].Length; j++)//获取列数
                {
                    if (matrix[i][j] <= min)
                        min = matrix[i][j];
                }
                minArray.Add(min);
            }
            return minArray.ToArray();
        }

        //遍历列 找出所有最大值
        public int[] GetColMax(int[][] matrix)
        {
            List<int> minArray = new List<int>();
            for (int i = 0; i < matrix[0].Length; i++)//获取行数
            {
                int max = matrix[0][i];
                for (int j = 0; j < matrix.GetLength(0); j++)//获取列数
                {
                    if (matrix[j][i] >= max)
                        max = matrix[j][i];
                }
                minArray.Add(max);
            }
            return minArray.ToArray();
        }
}
```