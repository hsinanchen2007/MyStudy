解题思路： 
1. `new int[]`为每一个航班初始化计数
2. 遍历`bookings`，把每个`booking`的`booking[2]`（`预订航班数`）分别加给： 从`booking[0]` 到 `booking[1]` 的航班
3. 返回计数结果


```java []
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] result = new int[n]; //为每一个航班初始化计数

        for (int[] booking : bookings) { //遍历航班bookings
            int start = booking[0]; //航班（from）
            int end = booking[1]; //航班（to）
            int count = booking[2]; //航班预订数
            while (start <= end) {
                result[start - 1] += count; //由于航班是从1开始，而结果数组下标是从0开始，所以下标减1
                start++;
            }
        }
        return result;
    }
}
```
