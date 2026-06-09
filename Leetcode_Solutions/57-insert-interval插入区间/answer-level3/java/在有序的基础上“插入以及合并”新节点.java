**解题思路：**
新的节点其实并不需要真正的插入，而是根据新节点的不同插入合并情况，在57题的基础上面稍作修改就可以了。

上一题解答：（注）参考了@powcai的代码

```
class Solution {
    public int[][] merge(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        if (intervals.length == 0 || intervals == null) return res.toArray(new int[0][]);
        
        int nleft = newInterval[0], nright = newInterval[1];
        
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int i = 0;
        while (i < intervals.length) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            while (i < intervals.length - 1 && intervals[i + 1][0] <= right) {
                i++;
                right = Math.max(right, intervals[i][1]);
            }
            res.add(new int[]{left, right});
            i++;
        }
        return res.toArray(new int[0][]);
    }
}
```
这一次不需要再次排序。而新节点插入以及合并有如下的几种情况。
首先我们要明确，排序的标准是新增节点的左端，而右端对于是否合并有影响。

```
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        if (intervals.length == 0 || intervals == null) {
            res.add(new int[]{newInterval[0], newInterval[1]});
            return res.toArray(new int[0][]);
        }
        
        int nleft = newInterval[0], nright = newInterval[1];
        
        int i = 0, left, right;
        boolean flag = false;
        while (i < intervals.length) {
            left = intervals[i][0];
            right = intervals[i][1];
            //new interval still not insert
            if (!flag) {
                //情形1：新增节点作为当前节点前一个节点插入，看作是新增了一个节点。
                if (nleft < left) {
                    left = nleft;
                    right = nright;
                    flag = true;
                    i = -1;//不确定新增节点是否会实际添加上去，于是回退使得新增节点成为待判断节点
                }
                //情形2：新增节点作为当前节点后一个节点插入或者与下一个节点合并
                else if (nleft > right && i < intervals.length - 1 &&
                nleft < intervals[i + 1][0] ) {
                    res.add(new int[]{left, right});
                    //情形2.1：只插入不合并
                    if (nright < intervals[i + 1][0]) {
                        res.add(new int[]{nleft, nright});
                        flag = true;
                        i++;
                        left = intervals[i][0];//当前节点的下一个节点成为待判断节点
                        right = intervals[i][1];
                    //情形2.2：插入并且与后一个节点合并
                    } else {
                        left = nleft;
                        right = Math.max(intervals[i + 1][1], nright);//合并后当前节点的下一个成为待判断节点
                        flag = true;
                    }
                //情形3：新增节点与当前节点合并（后合并）
                } 
                else if (nleft >= left && nleft <= right) {
                    right = Math.max(right, nright);
                    flag = true;
                } 
            }
            while (i < intervals.length - 1 && intervals[i + 1][0] <= right) {
                i++;
                right = Math.max(right, intervals[i][1]);
            }
            res.add(new int[]{left, right});
            i++;
        }
        //情形4：新增节点作为最后一个节点插入
        //（用flag作为标志，表明新增节点是否在之前插入过）
        if (!flag) {
            res.remove(res.get(intervals.length - 1));
            //insert as the last one
            if (nleft > intervals[intervals.length - 1][1]) {
                res.add(new int[]{intervals[intervals.length - 1][0], intervals[intervals.length - 1][1]});
                res.add(new int[]{nleft, nright});
            //merge
            } else {
                left = intervals[intervals.length - 1][0] < nleft ? intervals[intervals.length - 1][0] : nleft;
                right = intervals[intervals.length - 1][1] > nright ? intervals[intervals.length - 1][1] : nright;
                res.add(new int[]{left, right});
            }
        }
        return res.toArray(new int[0][]);
    }
}
```

