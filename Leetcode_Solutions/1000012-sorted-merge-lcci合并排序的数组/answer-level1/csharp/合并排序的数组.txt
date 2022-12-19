### 解题思路
题目本身没有什么难度，在本题中采用了指针法，解题思路就是利用数组已排序的优点，相比较两个数组的第一个数据大小，放入临时数组中,然后将指针移动到下一位，依次将所有数据放入临时数组，然后再赋值给A。
感觉本题的重点是要思路严谨，考虑到n为0的情况

### 代码

```csharp
public class Solution {
    public void Merge(int[] A, int m, int[] B, int n) {
        var C = new int[m + n];
        var index = 0;
        var pa = 0;
        var pb = 0;
        while (pa < m || pb < n)
        {
            if (pa == m )
            {
                C[index] = B[pb];
                pb++;
            }
            else if (pb == n)
            {
                C[index] = A[pa];
                pa++;
            }
            else if(A[pa] > B[pb])
            {
                C[index] = B[pb];
                pb++;
            }
            else
            {
                C[index] = A[pa];
                pa++;
            }
            index++;
        }
        for (int i = 0; i < m + n; i++)
        {
            A[i] = C[i];
        }
    }
}
```