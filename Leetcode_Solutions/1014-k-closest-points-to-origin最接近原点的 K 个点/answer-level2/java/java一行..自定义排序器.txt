自定义排序器,返回前K个即可

```
   public int[][] kClosest(int[][] points, int K) {
        Arrays.sort(points,(a,b)->((a[0]*a[0]+a[1]*a[1])-(b[0]*b[0]+b[1]*b[1])));
        return Arrays.copyOf(points, K);
    }
```
