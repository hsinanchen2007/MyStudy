### 解题思路
利用计数排序的思想先给A中元素安排好座位，如果座位上超过一个人就要向后找值为0的元素，
时间复杂度应该是，最坏情况全重复，n*n，最好情况全不重复n
![image.png](https://pic.leetcode-cn.com/ce3697c93a203c328e160c3ef8367c82eb0c5644097687b01100e3f13db08b73-image.png)

### 代码

```csharp
public class Solution {
    public int MinIncrementForUnique(int[] A) {
        if(A==null||A.Length<2) return 0;
        int min=A[0];
        int max=A[0];
        for(int i=1;i<A.Length;i++)
        {
            min=Math.Min(min,A[i]);
            max=Math.Max(max,A[i]);
        }
        int[] array=new int[max-min+1];
        for(int i=0;i<A.Length;i++)
        {
            array[A[i]-min]++;
        }
        int result=0;
        int index=0;
        for(int i=0;i<array.Length;i++)
        {
            if(array[i]<2) continue;
            for(int j=0;j<array[i]-1;j++)
            {
                index=Math.Max(index,i+1);
                while(index<array.Length&&array[index]!=0)
                        index++;
                result+=index-i;
                index++;
            }
        }
        return result;
    }
}
```