可以看成是在元素为 $0～target$ 的有序数组中查找两个数，使得这两个数的平方和为 $target$，如果能找到，则返回 `true`，表示 $target$ 是两个整数的平方和。

本题和 [167\. Two Sum II - Input array is sorted](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/shuang-zhi-zhen-on-shi-jian-fu-za-du-by-cyc2018/) 类似，只有一个明显区别：一个是求和为 $target$，一个是平方和为 $target$。可以和 $167$ 一样使用双指针得到两个数，使其平方和为 $target$。

本题的关键是右指针的初始化，实现剪枝，从而降低时间复杂度。设右指针为 $x$，左指针固定为 $0$，为了使  $0^2$  + $x^2$ 的值尽可能接近 $target$，我们可以将 $x$ 取为 $\sqrt{target}$。

因为最多只需要遍历一次 $1～\sqrt{target}$所以时间复杂度为 $O(log\ N)$。又因为只使用了两个额外的变量，因此空间复杂度为 $O(1)$。

```java [-Java]
 public boolean judgeSquareSum(int target) {
     if (target < 0) return false;
     int i = 0, j = (int) Math.sqrt(target);
     while (i <= j) {
         int powSum = i * i + j * j;
         if (powSum == target) {
             return true;
         } else if (powSum > target) {
             j--;
         } else {
             i++;
         }
     }
     return false;
 }
```