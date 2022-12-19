### 解题思路
数组反转`Array.Reverse(arr);`不用反转后再覆盖
`Array.Reverse(arr, begin, end);`
### 代码

```csharp
public class Solution {
    public int[][] FlipAndInvertImage(int[][] A) {
        for(int i = 0;i<A.Length;i++){
                for(int j = 0;j<A[i].Length;j++){
                        if(A[i][j]==1) A[i][j]=0;
                        else A[i][j]=1;
                }
                Array.Reverse(A[i]);
        }
            return A;
    }
}
```