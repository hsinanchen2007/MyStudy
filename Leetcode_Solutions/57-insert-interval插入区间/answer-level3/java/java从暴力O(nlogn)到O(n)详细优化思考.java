**思路一：暴力法** 先将intervals和新区间都输入到一个数组中，然后对数组中的区间进行合并得到结果。

[徒手挖地球二五周目](https://blog.csdn.net/qq_42758551/article/details/104662112)题解中NO.56合并区间中详细描述了如何进行区间合并。

```java
public int[][] insert(int[][] intervals, int[] newInterval) {
    int n = intervals.length;
    int[][] input=new int[n+1][2];
    //将newInterval和Intervals都输入一个数组
    for (int i = 0; i < n; i++) {
        input[i][0]=intervals[i][0];
        input[i][1]=intervals[i][1];
    }
    input[n][0]=newInterval[0];
    input[n][1]=newInterval[1];
    //合并区间
    return merger(input);
}

private int[][] merger(int[][] intervals) {
    List<int[]> res=new ArrayList<>();
    Arrays.sort(intervals,(o1,o2)->o1[0]-o2[0]);
    for (int i = 0; i < intervals.length; i++) {
        int left=intervals[i][0],right=intervals[i][1];
        while (i<intervals.length-1&&right>=intervals[i+1][0]){
            right=Math.max(right,intervals[i+1][1]);
            i++;
        }
        res.add(new int[]{left,right});
    }
    return res.toArray(new int[0][]);
}
```

时间复杂度：O(nlogn)	将新旧区间输入一个数组中需要遍历一次，合并区间操作需要排序是nlogn复杂度，然后合并本身需要遍历数组一次。

**思路二：贪心算法** 将当前的一小步进行最优处理，从而使整体最优。思路二是针对思路一进行优化。

本题中已经告知旧区间是有序的，所以思路一中的排序只是为了让新区间放置在末尾之后移动到有序的位置上，从而付出了nlogn的代价。

1. 针对这一点很容易想到，在第一次遍历旧区间合集的时候顺便进行和新区间的比较，就能直接将新区间插入到有序的位置上。如何进行比较？

   ==新区间应该放置到最后一个右边界小于新区间左边界的旧区间后面==，这样新区间放入位置之前的所有旧区间都不会和新区间重叠且不需要和新区间进行合并。

2. 找到新区间的插入位置后先不要急于将新区间放入，因为此时新区间可能需要和放入位置及其后序连续的旧区间进行合并。什么样的旧区间会和新区间进行合并？

   ==新区间右边界>=旧区间左边界==则说明新旧区间需要进行合并，例如[4,5]和[2,6]、[4,8]和[8,9]等等。。。

3. 两个区间合并的结果是[min(新区间左,旧区间左)，max(新区间右,旧区间右)]。将合并后的新区间加入结果集。最后将剩余的旧区间加入结果集。

```java
public int[][] insert(int[][] intervals, int[] newInterval) {
    List<int[]> res=new ArrayList<>();
    int index=0,n=intervals.length;
    //找到新区间的放置位置，最后一个右边界小于新区间左边界的旧区间的后面
    while (index<n&&newInterval[0]>intervals[index][1]){
        res.add(intervals[index++]);
    }
    //temp记录合并后新区间的左右边界值
    int temp[]=new int[]{newInterval[0],newInterval[1]};
    while (index<n&&newInterval[1]>=intervals[index][0]){
        temp[0]=Math.min(temp[0],intervals[index][0]);
        temp[1]=Math.max(temp[1],intervals[index][1]);
        index++;
    }
    //将合并后的新区间放入结果集
    res.add(temp);
    //将剩余区间放入结果集
    while (index<n){
        res.add(intervals[index++]);
    }
    return res.toArray(new int[0][]);
}
```

时间复杂度：O(n)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/) 