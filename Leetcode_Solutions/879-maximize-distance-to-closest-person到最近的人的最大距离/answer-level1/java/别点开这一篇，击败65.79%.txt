### 解题思路
我这个方法是从0出发，计算0的数量
但也因此在for循环中有许多if判断，每遍历一个数字，就要做1-3个if判断。

如果从1出发，先遍历出1的位置，然后来计算0的数量，速度会快不少。

0的状况有三种，101， 001，100。因为边界为0的情况对间隔座位数量不一样。

### 代码

```java
class Solution {
    public int maxDistToClosest(int[] seats) {

        int count = 0, ans = 0;

        boolean startIsOne = false;

        for(int i = 0; i < seats.length; i++){

            if(seats[i] == 0){
                count++;
            }else{
                int start1 = i - 1 - count;
                int start2 = i - count;
                int temp = (start1) >= 0 ?  (start1) : (start2);
                if(seats[temp] == 1){
                    count = (count + 1) / 2;
                }
                ans = ans > count ? ans : count;
                count = 0;
                startIsOne = false;
            }
        }

        return ans > count ? ans : count;
    }
}
```