### 解题思路
取能取到的最多的油，取过的置空


### 代码

```java
class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        if (startFuel >= target) {
            return 0;
        }
        int result = startFuel;
        int count = 0;
        for (int i = 0; i <= stations.length; i++) {
            if (i == stations.length) {
                if (result >= target) {
                    return count;
                } else {
                    return -1;
                }
            }
            if (result >= target) {
                return count;
            } else {
                int temp = result;
                result = pick(target, result, stations);
                if (result == temp) {
                    return -1;
                }
                count++;
            }
        }
        return count;
    }

    public int pick(int target, int startFuel, int[][] stations) {
        int result = startFuel;
        int max = 0;
        int maxindex=0;
        for (int i=0;i<stations.length;i++) {

            if (stations[i][0] > result) {
                break;
            }
            if (stations[i][1] > max) {
                max = stations[i][1];
                maxindex=i;
            }
        }
        stations[maxindex][1]=0;
        result += max;
        return result;
    }

}
```