### 解题思路
例子：
0 8 mid=4
0 3 mid=1
1 3 mid=2
2 3 mid=2
3 3 mid=3
3 2 
采坑1：右边界 right 最好从 x/2开始，不容易越界。但此时 要求x>=2是才能二分，即x=1时，右边界x/2为0
或者直接右边界从x开始。
当x>2, sqrt(x) <= x/2 
一般情况x>=0， sqrt(x) <= x
采坑2：计算平方时，可能越界，变量定义为long类型且计算前需要将mid转化成long再计算，否则也会越界。
注意1：while的结束条件是left <= right,
因为如果是left < right则mid无法取值到left=right的值。
注意2：最后越界返回right的值
分析为何越界返回right的值？
因为，mid = (left+right)/2 是向下取整
当left和right的差值为1的时候，mid 必然取值left
如果left*left < x时， 则left加1,等于right。
如果right*right > x时，则right将减1，此时right = left - 1,循环条件不满足。
综上可知，如果一旦来到left = right -1时，且 left*left != x && right*right != x
必定结束循环时，有left = right + 1

题目要求：只保留整数的部分，小数部分将被舍去。
返回值必定在left和right之间其中一个，且是小的那个。
### 代码

```java
class Solution {
    public int mySqrt(int x) {
        //if(x <= 1) return x; 加此边界，right可以取x/2开始。
        int left = 0, right = x;
        while(left <= right) {
            int mid = left + (right-left)/2;
            long temp = (long) mid*mid;
            if(temp == x){
                return mid;
            } else if(temp > x){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
}
    
```