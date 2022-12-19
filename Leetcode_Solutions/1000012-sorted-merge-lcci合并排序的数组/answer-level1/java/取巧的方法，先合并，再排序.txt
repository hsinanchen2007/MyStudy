### 解题思路
 先利用ArrayList底层的拷贝数组的方法将B拷贝到A，然后再排序。

这种写法很取巧， 除了常用的排序算法外，还可以用双指针解决。

### 代码

```java
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
         System.arraycopy(B,0,A,m,n);
        Arrays.sort(A);
    }
}
```