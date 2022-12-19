### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
          
           //定义一个数组存放最小的k个数
            List<int> LeastNumbersList = new List<int>();
            //判断k的合法范围
            if (k<0||k>arr.Length)
            {
                Console.WriteLine("k的范围不对");
                return LeastNumbersList.ToArray();
            }
           
            //先进行排序
            int[] Sorted = SelectionSort(arr);

            for (int i = 0; i < k; i++)
            {
                LeastNumbersList.Add(Sorted[i]);
            }
            return LeastNumbersList.ToArray();
    }
      public static int[] SelectionSort(int[] a)
        {
            int item; //中间临时变量，用于交换元素位置
            for (int i = 0; i < a.Length; i++)
            {
                int minIndex = i; //记录最小元素的下标
                for (int j = i + 1; j < a.Length; j++)
                {
                    if (a[minIndex] > a[j])
                    {
                        minIndex = j;
                    }
                }
                if (a[minIndex] != a[i])
                {
                    item = a[i];
                    a[i] = a[minIndex];
                    a[minIndex] = item;
                }
                //StringBuilder sb = new StringBuilder();
                //sb.Append($"第{i + 1}次排序后：");
                //foreach (var num in a)
                //{
                //    sb.Append($"{num},");
                //}
                //Console.WriteLine(sb.ToString());
            }
            return a;
        }
}
```