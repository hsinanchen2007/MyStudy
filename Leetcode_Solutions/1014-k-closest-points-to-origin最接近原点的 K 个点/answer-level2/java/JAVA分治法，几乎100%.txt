### 解题思路
分治法的思路官方题解已经讲的很清楚，即用快速排序中的split方法将第一个元素（或者随机的一个元素）归位，然后通过比较`j-low+1`与K的大小（即在归位元素左边的元素个数），来判断在左边还是右边进行递归。

### 代码

```java
class Solution {
    public static int[][] p;
    public int[][] kClosest(int[][] points, int K) {
        this.p = points;
        work(0, p.length - 1, K);
        return Arrays.copyOfRange(p, 0, K);
    }
    public void work(int low,int high, int K)
    {    
        if(low >= high) return;
        int temp = dist(low);
        int j = low;
        for(int i = low+1 ; i < high+1 ; i++)
        {
            if(dist(i) <= temp)
            {
                j++;
                if(i != j)
                    swap(i,j);
            }
        }
        swap(low,j);
        if(j-low+1 < K) work(j+1,high,K-(j-low+1));
        else if(j-low + 1 > K) work(low,j,K);
        else return;
    }
    public int dist(int i)
    {
        return p[i][0] * p[i][0] + p[i][1]*p[i][1];
    }
    public void swap(int i ,int j)
    {
        int t0 = p[i][0];
        int t1 = p[i][1];
        p[i][0] = p[j][0];
        p[i][1] = p[j][1];
        p[j][0] = t0;
        p[j][1] = t1;
    }
}
```