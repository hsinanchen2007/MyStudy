### 解题思路
此处撰写解题思路
如解答

### 代码

```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
            int totalCacity = 0;
            int len = trips.length;
            int[][] tripdata = new int[len*2][2];
            for (int i = 0; i < len; i++) {
                tripdata[2*i][0] = trips[i][1];
                tripdata[2*i][1] = trips[i][0];
                tripdata[ 2*i + 1 ][0] = trips[i][2];
                tripdata[ 2*i + 1 ][1] = -1 * trips[i][0];
            }
           Arrays.sort(tripdata,(x,y) -> (x[0]==y[0] ? x[1] - y[1] : x[0] - y[0]));
            for (int i = 0; i < 2*len  ; i++) {
                totalCacity = totalCacity + tripdata[i][1];
                if(totalCacity > capacity)
                    return false;
            }
            return true;        
    }
}
```