一开始看到通过二分法在矩阵元素的最大值和最小值之间查找恰好使小于等于该值的矩阵元素为k个的值，这个值即为所求结果的方法，觉得有可能查到的值不在矩阵元素中，但后来发现如果并不是一查到符合条件的值（小于等于该值的矩阵元素有k个）就返回，而是继续二分，直到上下界相等，然后返回此时的下界/上界，由于矩阵中均为整数，是可以保证查到的值在矩阵内且小于等于该值的矩阵元素恰好有k个的。

实现代码如下：
```
class Solution {
    int[][] mat;
    public int kthSmallest(int[][] matrix, int k) {
        mat=matrix;
        int n=matrix.length;
        int min=matrix[0][0];
        int max=matrix[n-1][n-1];
        while (min<max) {
            int mid=(min+max)/2;
            int lesscount=lessCount(mid);
            if (lesscount<k) min=mid+1;
            else max=mid;
        }
        return min;
    }
    private int lessCount(int a) {
        int col=mat.length-1;
        int row=0;
        int count=0;
        while (row<=mat.length-1 && col>=0) {
            if (mat[row][col]<=a) {
                count+=col+1;
            row++;}
            else col--;
        }
        return count;
    }
}
```
证明如下：
设min^{t}为第t轮二分的min，mid^{t}为第t轮二分的mid,max^{t}为第t轮二分的max,target是我们要查找的值。

因此min^{t}=min^{t-1}或者min^{t}=mid^{t-1}+1。如果min^{t}=mid^{t-1}+1,说明小于等于mid^{t-1}的矩阵中元素的个数小于k,说明mid^{t-1}<target,那么min^{t}=mid^{t-1}+1<target+1,即min^{t}<=target。因此，只要其中有一次的min是由上一轮的mid转化而来的，那么就可以保证min始终<=target。如果min一直保持着初始状态，从来没有从上一轮mid转化而来过，那么min^{t}=min{1}<=target。因此，min始终小于等于target。

同时，max^{t}=mid^{t-1}或者max^{t}=max^{t-1}。如果max^{t}=mid^{t-1},说明小于等于mid^{t-1}的矩阵中的元素的个数>=k，说明mid^{t-1}>=target。因此，只要其中有一次的max是由上一轮的mid转化而来的，那么就可以保证max始终>=target。如果max一直保持着初始状态，从来没有从上一轮mid转化而来过，那么max^{t}=max{1}>=target。因此，max始终大于等于target。

此外，由于min和max构成的区间是在不断缩小的，所以最终肯定可以达到min=max的状态，从而退出循环。此时，由于min<=target,max>=target,而min=max，所以min=max=target。

得证。
