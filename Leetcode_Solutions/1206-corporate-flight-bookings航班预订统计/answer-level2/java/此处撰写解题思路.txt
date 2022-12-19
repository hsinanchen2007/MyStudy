### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
            int[] nums = new int[n];


            for (int i = 0 ; i < bookings.length; i++) {
                int j = bookings[i][0];
                int k = bookings[i][1];
                int val =  bookings[i][2];

                for (int l = j-1; l < k; l++) {
                    nums[l] += val;
                }
            }

            System.out.println(Arrays.toString(nums));
            return nums;
    }
}
```