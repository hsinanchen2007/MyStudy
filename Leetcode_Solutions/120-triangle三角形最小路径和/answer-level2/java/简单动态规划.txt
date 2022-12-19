### 解题思路
第`i`层的某个顶点向下选择相邻的两个点时，显然必须选择这样一个点：以该点为顶点构成的三角形中的路径和最短。
这就得到了动态规划的一个子问题解。
具体解决看代码，从下到上慢慢构造路径和最小的三角形。简单易懂。
### 代码

```java
class Solution {
    
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle.size()==0)return 0;
        int size=triangle.size();
        int[] mintriangle=new int[triangle.get(size-1).size()];
        int i=0;
        for(int e:triangle.get(size-1))
            mintriangle[i++]=e;
        for(i=size-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                int top=triangle.get(i).get(j);
                mintriangle[j]=Math.min(mintriangle[j]+top,mintriangle[j+1]+top);
            }
        }
        return mintriangle[0];
    }
}
```