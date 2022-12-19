### 解题思路
一开始，是这样的。。。
### 代码

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        int[] res = new int[n];
        for(int i=0;i<bookings.length;i++){
            for(int start = bookings[i][0];start<=bookings[i][1];start++)
            {
                res[start-1] += bookings[i][2] ;
            }
        }
        return res;
    }
}
```
结果。。。
![image.png](https://pic.leetcode-cn.com/47a642cef681115642f762e6bc27f6ea6231d3c4e83e5c8f76c07418171b1bfc-image.png)

后面看了大佬的思路，可以看做是公交车到站上车下车问题。。。结果。。

### 代码

```java
class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        //count[0]用来存放初始车上人数，后面的用来存放车上人数的变化
        int[] count = new int[n];
        for(int[] booking :bookings){
            count[booking[0]-1] += booking[2];
            //有可能是i到n，即一直到终点站，这些人不下车了，所以此时count[n]会超过数组界面，需要判断
            if(booking[1]<n){
                count[booking[1]] -= booking[2];
            }
        }
        for(int i=1;i<n;i++)
            count[i] += count[i-1];

        return count;
    }
}
```
![image.png](https://pic.leetcode-cn.com/3421cd78103a1edbc67f32c85978aaff79c1a7ea005f4df9119ac7135002f90b-image.png)

果然是大佬强啊。。。
