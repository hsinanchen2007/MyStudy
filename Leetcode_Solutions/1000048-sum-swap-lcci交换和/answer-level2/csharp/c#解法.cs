### 解题思路
交换的两个数的差值一定是d = (sum(A) - sum(B)) / 2
之后找差值是d的两个数，注意考虑用集合过滤掉重复的数

### 代码

```csharp
public class Solution {
    public int[] FindSwapValues(int[] array1, int[] array2) {
        int sum1 = 0;
        for(int i = 0; i < array1.Length; i++)
        {
            sum1 += array1[i];
        }

        int sum2 = 0;
        for(int i = 0; i < array2.Length; i++)
        {
            sum2 += array2[i];

        }

        if((sum1 + sum2) % 2 != 0)
        {
            return new int[0];
        }

        int middle = (sum1 - sum2) / 2;

        HashSet<int> set1 = new HashSet<int>(array1);
        HashSet<int> set2 = new HashSet<int>(array2);

        foreach(int a in set1)
        {
            foreach(int b in set2)
            {
                if(a - b == middle)
                {
                    return new int[]{a, b};
                }
            }
        }

        return new int[0];
    }
}
```