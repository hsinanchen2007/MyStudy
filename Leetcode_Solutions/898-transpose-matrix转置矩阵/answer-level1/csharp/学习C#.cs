这里并不能直接声明二维数组的长和宽，并不知道为啥，或者是有什么其他的办法
`int[][] B = new int[A[0].Length][A.Length];`这样的这样的声明是不行的。好麻烦啊
```C#
public class Solution {
    public int[][] Transpose(int[][] A) {
        int[][] B=new int[A[0].Length][];
        for(int i = 0;i<A[0].Length;i++)
        {
            B[i]=new int[A.Length];
            for(int j=0;j<A.Length;j++)
            {
                B[i][j]=A[j][i];
            }
        }
        return B;
    }
}
```

