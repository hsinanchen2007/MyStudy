**思路1：** 在118的基础上改造，到了指定行直接返回。
```csharp
public class Solution {
    public IList<int> GetRow(int rowIndex) {
        IList<IList<int>> result = new List<IList<int>>();
            for (int i = 0; i <= rowIndex; i++)
            {
                var list = new List<int>(i + 1);
                for (int j = 0; j < i + 1; j++)
                {
                    int element;
                    if (i == 0 || j == 0 || j == i)
                    {
                        element = 1;
                    }
                    else
                    {
                        element = result[i - 1][j - 1] + result[i - 1][j];
                    }

                    list.Add(element);
                }

                if (rowIndex == i)
                {
                    return list;
                }
                result.Add(list);
            }

            return result.Last();
    }
}
```

**思路2：**  公式法，由于每一次的计算涉及乘除法，所以整体的时间效率并不高。
```
public IList<int> GetRow2(int rowIndex)
        {
            var result = new List<int>();

            for (int i = 0; i <= rowIndex; i++)
            {
                //节省一半算力
                if (i > rowIndex / 2)
                {
                    result.Add(result[rowIndex - i]);
                }
                else
                {
                    result.Add(CalculateValue(rowIndex, i));
                }
            }

            return result;
        }

        private int CalculateValue(int rowIndex, int columnIndex)
        {
            long result = 1;

            for (int i = 1; i <= columnIndex; i++)
            {
                result = result * (rowIndex - columnIndex + i) / i;
            }

            return (int)result;
        }
```
