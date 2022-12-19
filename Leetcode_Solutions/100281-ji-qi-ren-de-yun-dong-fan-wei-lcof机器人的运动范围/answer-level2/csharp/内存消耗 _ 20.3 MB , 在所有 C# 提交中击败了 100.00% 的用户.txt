### 解题思路
递归求解，注意需要用一个HashSet来控制不要有重复的数组，因而需要重写相等的比较器，实现接口IEqualityComparer<int[]>即可

### 代码

```csharp
public class Solution {
    public int MovingCount(int m, int n, int k) {
         TestCompare compare = new TestCompare();
            int i = 0;
            int j = 0;
            int sum = 0;
            HashSet<int[]> set = new HashSet<int[]>(compare);
            GetCount(i, j, k, ref sum, m, n, set);
            return sum;
    }
     public  void GetCount(int i, int j, int k, ref int sum, int m, int n, HashSet<int[]> set)
        {
            if (i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1)
            {
                int[] temp = new int[] { i, j };
                if (Get(i, j, k) && !set.Contains(temp))
                {
                    sum++;
                    set.Add(temp);
                    GetCount(i + 1, j, k, ref sum, m, n, set);
                    GetCount(i, j + 1, k, ref sum, m, n, set);
                    //GetCount(i-1, j, k, ref sum, m, n, set);
                    //GetCount(i, j-1, k, ref sum, m, n, set);
                }
            }
            else
            {
                return;
            }
        }
        public  bool Get(int m, int n, int k)
        {
            List<int> list = new List<int>();
            while (m != 0)
            {
                list.Add(m % 10);
                m = m / 10;
            }
            while (n != 0)
            {
                list.Add(n % 10);
                n = n / 10;
            }
            int temp = 0;
            for (int i = 0; i < list.Count; i++)
            {
                temp += list[i];
            }
            return temp <= k ? true : false;
        }
}
 class TestCompare :IEqualityComparer<int[]>
    {
        
        public bool Equals( int[] x,  int[] y)
        {
            for(int i = 0; i < x.Length; i++)
            {
                if (x[i] != y[i])
                {
                    return false;
                }
            }
            return true;
        }

        public int GetHashCode(int[] obj)
        {
            return base.GetHashCode();
        }
    }
```