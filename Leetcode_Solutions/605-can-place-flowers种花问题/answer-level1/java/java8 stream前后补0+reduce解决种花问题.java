最近在学习java8的Stream，体验一把java上的函数式编程，用的是stream的reduce函数。
思路是先利用Stream的拼接前后补0，然后开始数空格，以3为一轮回，遇到花就把空格数减去空格数除3的余数，因为花之间的0、1、2个空格是不能种花的；每凑满3个空格（模3为0）就多记一个空格，因为两朵连续的花中间共享一个空格。
```
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        return  n == IntStream.concat(IntStream.of(0), IntStream.concat(IntStream.of(flowerbed), IntStream.of(0))).reduce(0, (e, p) -> {
      if (e /3 >= n) {
        return n * 3;
      }
      if (1 == p) {
        return e -= e % 3;
      } else {
        if ((e + 1) % 3 == 0) {
          return e + 2;
        } else {
          return e + 1;
        }
      }
    }) / 3;
    }
}
```
