```
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
```

```java
/*
time:o(N)
*/
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        for(int[] i:intervals){
          	///新加的入的节点在当前节点后边
            //i[0] i[1] newInterval[0] newInterval[1]
            if(newInterval==null || i[1]<newInterval[0]){
                res.add(i);
            //新加入的节点在当前节点的前边
            //newInterval[0] newInterval[1] i[0] i[1]
            }else if(i[0]>newInterval[1]){
                res.add(newInterval);
                res.add(i);
                newInterval = null;
            }else{
            //新加入的节点和当前节点有重合，更新节点
                newInterval[0] = Math.min(newInterval[0], i[0]);
                newInterval[1] = Math.max(newInterval[1], i[1]);
            }
        }
        //有可能newInterval 在所有的节点后边，也就是第一个if语句，我们最后把它放入结果
        if(newInterval != null){
            res.add(newInterval);
        }
        return res.toArray(new int[res.size()][]);
    }
}
```
```java
//method2
//先插入区间 得到一个新的数组，并进行排序，然后再合并区间
//方法基于74题合并区间
//o(nlogn)
class Solution {
    private class IntervalComparator implements Comparator<int[]> {
    public int compare(int[] v, int[] w) {
        return v[0]-w[0];
        }
	}
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> tmp = new ArrayList<>();
        for(int[] i : intervals){
            tmp.add(i);
        }
        tmp.add(newInterval);
        tmp.sort(new IntervalComparator());
        //剩下的和56题几乎一样
        List<int[]> res = new ArrayList<>();
        for(int i=0;i<tmp.size(); i++){
            int left = tmp.get(i)[0];
            int right = tmp.get(i)[1];
            while(i<tmp.size()-1&&tmp.get(i+1)[0]<=right){
                right = Math.max(right, tmp.get(i+1)[1]);
                i++;
            }
            res.add(new int[]{left,right});
        }
        return res.toArray(new int[res.size()][]);
    }
}
```

