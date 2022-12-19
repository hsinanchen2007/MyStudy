### 解题思路
遍历一边先求出所有值对60余数，范围在0-59之间，然后1和59，2和58，......,29和31配对，0 和 30 单独处理，即可。

### 代码

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int sum = 0;
        
        int[] rem = new int[60];
        for (int n:time) {
            rem[n%60]++;
        }
        for (int i=0; i<=30; ++i) {
            if(i == 0 || i == 30) {
                sum += (rem[i]*(rem[i]-1))/2;
            }else {
                sum += rem[i] * rem[60 - i];
            }
        }
        return sum;
    }
}
```