### 解题思路
取分发值和剩余糖果的最小值进行分发即可
### 代码

```java
class Solution {
  public int[] distributeCandies(int candies, int num_people) {
        int count = 1 ;
        int [] a = new int[num_people];
        while (candies>0){
           int giveout = Math.min(count,candies);
                a[(count-1)%num_people] += giveout;
                candies-= giveout;
            count ++ ;
        }
        return  a ;
    }
}
```