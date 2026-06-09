### 解题思路
![image.png](https://pic.leetcode-cn.com/8d261cb55ff58f946960a010ef01cf21503fdfcc7b86f6cfe0d162deb28f1e68-image.png)

将所有行程的上车与下车情况记录在一个一维数组中，上车记录负数，表示容量减小；下车记录负数，表示容量增加。最后遍历该数组，同时对capacity求和，当其小于0时，说明不能完成任务，返回false；否则，遍历结束后返回true。

### 代码

```java
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        //特殊情况下，直接返回
        if(trips.length == 0 || trips[0].length == 0) {
            return true;
        }
        if(trips.length == 1 && trips[0][0] <= capacity) {
            return true;
        }

        int[] record = new int[1001];
        for(int i = 0; i < trips.length; i++) {
            record[trips[i][1]] += (0 - trips[i][0]);
            record[trips[i][2]] += trips[i][0];
        }
        for(int j = 0; j < 1001; j++) {
            capacity += record[j];
            if(capacity < 0)
                return false;
        }
        return true;
    }
}
```