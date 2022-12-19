### 解题思路
先进行排序，然后判断相邻右边元素是否小于等于左边，若是则右边为左边加一

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length<=1)
            return 0;
        Arrays.sort(A);
        int times = 0;
        for(int i=1;i<A.length;i++)
        {
            if(A[i]<=A[i-1])
            {
                int a = A[i];
                A[i] = (A[i-1]+1);
                times +=(A[i] - a);
            }
        }
        return times;
        
    }
}
```