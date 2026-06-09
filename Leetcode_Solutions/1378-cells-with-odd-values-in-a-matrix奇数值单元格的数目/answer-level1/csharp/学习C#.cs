### 解题思路
c#的二维数组定义太神奇了`int[,] tmp = new int[n,m];`
可以直接用foreach遍历每一个数，`foreach(int t in tmp)`
二维数组的调取也跟平常不一样 `tmp[i[0],j]`
`int[][] arr = new int[3][];`可以定义不规则数组
之后要分别再像一维数组定义
### 代码

```csharp
public class Solution {
    public int OddCells(int n, int m, int[][] indices) {
        int[,] tmp = new int[n,m];
            foreach(int[] i in indices){
                    Console.WriteLine(i[0]+" "+i[1]);
                for(int j = 0;j<m;j++) {tmp[i[0],j]++;}
                for(int k = 0;k<n;k++) {tmp[k,i[1]]++;}
        }
            int res = 0;
            foreach(int t in tmp){
                   if(t%2==1) res++;
            }
            return res;
    }
}
```