这个思路是按照leetcode官方题解而来的。leetcode官方写的太复杂了，映射，重叠什么的，我用简单的话来讲。  
**核心思路**：让A中的1所在的点去移动到B中1所在的点。之后去判断A中所有的1所在的位置加上这段位移之后是否与B之中的1位置重合。  
举例来说，A中第一个为1的点A1（0，0），去找B中第一个1点（1，1），需要的位移是右移1，下移1，那么我们让A中所有值为1的点都加上这个位移，然后每个去判断是否与B中值为1点的位置重合。  
```java
A = [[1,1,0],
          [0,1,0],
          [0,1,0]]
     B = [[0,0,0],
          [0,1,1],
          [0,0,1]]
```
**具体思路**:我们将A和B中的值为1的点位置存储至两个List（ListA，ListB）中，并根据ListB做一个HashSet，然后ListA中的每一个点去对应ListB中的每一个点去做位移，找到位移之后，让ListA中每一个点加上这个位移，去判断是否在HashSet中，在HashSet中存在的话，（cand值）就增加1，每一次循环结束让cand与sum（当前最大重合量）比较，最终求出最大值。 
 **需要注意：**我们存储A和B中的点的方式是使用java自带的Point类，我们在求位移的时候，也是创建一个新的Point, 这样就很有效的处理了二维的数据。  
```java
import java.awt.Point;

class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int N = A.length;
        List<Point> A2 = new ArrayList(), B2 = new ArrayList();
        for (int i = 0; i < N; i++) {
            for(int j=0; j<N; j++){
            //将等于1的点添加进去。
            if (A[i][j] == 1) A2.add(new Point(i, j));
            if (B[i][j] == 1) B2.add(new Point(i, j));
        }
        }
        Set<Point> Bset = new HashSet(B2);

        int ans = 0;
        Set<Point> seen = new HashSet();
        for (Point a: A2){
            //对应A中每个1去与B中每个1去重合
            for (Point b: B2) {
            //这个delta可以理解为A中的点a要走到b这个点需要走多少。例如A中第一个1，走到B中第1个1
            //需要右移动1（b.x-a.x），向下移动1（b.y-a.y）。
            Point delta = new Point(b.x - a.x, b.y - a.y);
            //为了避免相同的位移。比如A中（0，1）处的1想到B中（1，2）处的1也是需要向右移动1，向下移动1
            //那么我们之前计算过一遍就不需要再计算一次了。
            if (!seen.contains(delta)) {
                seen.add(delta);
                int cand = 0;
                //对于A2中的每个点加上位移，去判断是否与B重合
                for (Point p: A2){
                    if (Bset.contains(new Point(p.x + delta.x, p.y + delta.y)))
                        cand++;
                }
                ans = Math.max(ans, cand);
            }
        }
        }

        return ans;
    }
}
```
