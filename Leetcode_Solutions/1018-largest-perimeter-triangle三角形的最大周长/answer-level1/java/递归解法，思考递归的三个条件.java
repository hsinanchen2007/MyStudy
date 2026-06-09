前边对于数组进行排序就不赘述了，我来分享一种递归解决此题的方法。
使用递归很直接，就是就意味着空间复杂度的提高，这点我不在此讨论优化的问题。

由三角形的最大周长可以知道，我们排序后要找的三个数应该在最后几位，从数组最后一位开始找，直到找到某个数的值小于此数的前两值之和，返回之，否则就返回0。

根据这个思路，和写递归代码需要满足的三个条件：
1，将一个问题分解为子问题
2，分解为子问题后，出了数据规模不同，求解思路完全一致
3，存在递归终止条件

针对此题，要思考从什么地方开始递归，递归的终止条件是什么？
从什么地方开始呢？
此题虽说求得是三个数之和，但是实际上，我们找的就是那个三角形的长，找到了长，前两个数就是他的两个边。
终止条件即为数组的长度，每一次递归为了迎合最大数，都会把数组长度减1；
思路其实和官方题解基本一样，只是采用了递归的方式。
下面贴代码：
```
class Solution {
    public int largestPerimeter(int[] a) {
         Arrays.sort(a);
        return getLargestPerimeter(a);
        
    }
    private int getLargestPerimeter(int[] a) {
      if(a.length>3){
        if(a[a.length-1] >= a[a.length-2]+a[a.length-3]){
            return getLargestPerimeter(Arrays.copyOfRange(a,0,a.length-1));
        }else if(a[a.length-1] < a[a.length-2]+a[a.length-3]){
            return a[a.length-1]+a[a.length-2]+a[a.length-3];
        }
    }
return a[a.length-1] >= a[a.length-2]+a[a.length-3]?0:a[a.length-1]+a[a.length-2]+[a.length-3;
    }
}
```

















