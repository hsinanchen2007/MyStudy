方法简单，根据有序性直接处理每一个区间。
当前区间与新区间有三种关系：
1.没有重叠，新区间在左边
2.没有重叠，新区间在右边
3.有重叠，合并区间


```java


    public int[][] insert(int[][] intervals, int[] newInterval) {
        LinkedList<int[]> res = new LinkedList<>();
        //参数检查
        if (intervals == null || intervals.length == 0) {
            res.add(newInterval);
            return res.toArray(new int[0][]);
        }
        //参数检查
        if (newInterval == null || newInterval.length == 0) {
            return intervals;
        }
        //区间是否已经插入进去了
        boolean insert = false;
        for (int i = 0; i < intervals.length; i++) {

            //插入后，只需处理后面的区间，只需要考虑合并问题
            if (insert) {
                if (res.getLast()[1] >= intervals[i][0]) {
                    res.getLast()[1] = Math.max(res.getLast()[1], intervals[i][1]);
                } else {
                    res.add(intervals[i]);
                }
            } else { //还没有插入区间
                //如果list中为空。就先放一个进去
                if (res.isEmpty()) {
                    //没有重叠，新区间在左边
                    if (newInterval[1] < intervals[0][0]) {
                        res.add(newInterval);
                        res.add(intervals[0]);
                        insert = true;
                    } else if (newInterval[0] > intervals[0][1]) { //没有重叠，新区间在右边
                        res.add(intervals[0]);
                    } else { //有重叠，合并区间
                        int[] tmpArr = new int[2];
                        tmpArr[0] = Math.min(intervals[0][0], newInterval[0]);
                        tmpArr[1] = Math.max(intervals[0][1], newInterval[1]);
                        res.add(tmpArr);
                        insert = true;
                    }
                } else {
                    //list中有区间了，就需要不断比较
                    //最后放入的区间包括新区间，即重叠了
                    if (res.getLast()[1] >= newInterval[0]) {
                        //拿出已经放进去的区间跟新区间进行比较
                        int[] inter = res.pollLast();
                        //没有重叠，新区间在左边
                        if (newInterval[1] < inter[0]) {
                            res.add(newInterval);
                            res.add(inter);
                        } else if (inter[1] < newInterval[0]) { //没有重叠，新区间在右边
                            res.add(inter);
                            res.add(newInterval);
                        } else {  //有重叠，合并区间
                            int[] tmpArr = new int[2];
                            tmpArr[0] = Math.min(inter[0], newInterval[0]);
                            tmpArr[1] = Math.max(inter[1], newInterval[1]);
                            res.add(tmpArr);
                        }
                        //当前区间并没有处理，退回去
                        i--;
                        insert = true;
                    } else {
                        //没有重叠，直接放置
                        res.add(intervals[i]);
                    }
                }

            }

        }

        //处理最后的区间
        if (!insert) {
            int[] inter = res.pollLast();
            if (newInterval[1] < inter[0]) {
                res.add(newInterval);
                res.add(inter);
            } else if (inter[1] < newInterval[0]) {
                res.add(inter);
                res.add(newInterval);
            } else {
                int[] tmpArr = new int[2];
                tmpArr[0] = Math.min(inter[0], newInterval[0]);
                tmpArr[1] = Math.max(inter[1], newInterval[1]);
                res.add(tmpArr);
            }

        }

        //列表转数组，返回结果
        return res.toArray(new int[0][]);
    }

```