起初直接算出直线斜率，存储到pair中，然后记录这条直线上有多少点，记录到一个HashMap<Pair, Integer>中，但是有个专门搞精度的测试数据`{{0,0},{94911151,94911150},{94911152,94911151}}`,以至于本来是两条不同直线丢失精度后被认为是同一条，所以不直接算出k和b（y=kx+b）。而是用gcd约分。

感谢qiaozhiwu, 虽然有思路，但是自己代码写得太丑了，参考了大神的。同时也有些优化，Pair也可以用`javafx.util.Pair`中的。
```java
class Solution {
    class Pair {
        Double k;
        Double b;

        public Pair(double k, double b) {
            this.k = k;
            this.b = b;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == this)
                return true;
            if (!(obj instanceof Pair))
                return false;
            Pair pair = (Pair) obj;
            return pair.k.equals(k) && pair.b.equals(b);
        }

        @Override
        public int hashCode() {
            int result = 17;
            result = 31 * result + k.hashCode();
            result = 31 * result + b.hashCode();
            return result;
        }
    }
    private int gcd(int a, int b){
        return b==0 ? a:gcd(b, a%b);
    }

    public int maxPoints(int[][] points) {
        if (points.length == 0 || points==null)
            return 0;
        int maxp = 1;
        for (int i = 0; i < points.length; i++) {
            HashMap<Pair, Integer> map = new HashMap<>();
            int duplicate = 0;
            int maxp_i = 1;
            for (int j = i + 1; j < points.length; j++) {
                int xi=points[i][0],yi=points[i][1];
                int xj=points[j][0],yj=points[j][1];
                if(xi==xj && yi==yj){
                    duplicate++;
                    continue;
                }
                int nx=xj-xi,ny=yj-yi,gcdn=gcd(nx,ny);
                nx/=gcdn;
                ny/=gcdn;
                Pair pair=new Pair(nx,ny);
                map.put(pair, map.getOrDefault(pair, 1)+1);
                maxp_i = Math.max(maxp_i, map.get(pair));
            }
            maxp = Math.max(maxp, maxp_i+duplicate);
        }
        return maxp;
    }
}
```
