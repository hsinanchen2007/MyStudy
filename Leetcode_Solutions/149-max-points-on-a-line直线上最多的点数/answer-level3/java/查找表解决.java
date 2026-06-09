### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
public static int maxPoints(int[][] points){

        if (points == null || points.length < 1)
            return 0;
        int max = 0;
        for (int i = 0; i < points.length; i++) {
            int res = 0;
            Map<Double,Integer> map = new HashMap<>();
            int same = 0;
            for (int j = 0; j < points.length; j++) {
                if (i != j){
                  if (isSame(points[i],points[j])) {
                      same++;
                     continue;
                  }
                  double k = getk(points[i],points[j]);
                  if (!map.containsKey(k)){
                      map.put(k,1);
                  }
                  else {
                      map.put(k,map.get(k)+1);
                  }
                }
            }
         
            for (Double key:map.keySet()){
                res= res < map.get(key)? map.get(key):res;
            }
            res += same;
            res++;
            max = max>res?max:res;
        } 
        return max;
    }
    private static Double getk(int[] a,int[] b){
       double res = 0.0;
       if (b[0] - a[0] == 0)
           res = Double.MAX_VALUE;
       else
           res = (b[1] - a[1])*1000.0 / (b[0]-a[0])*1.0;
       return res;
    }
    private static Boolean isSame(int[] a,int[] b){
        if (a[0] == b[0] && a[1] == b[1])
            return true;
        else
            return false;

    }

}
```