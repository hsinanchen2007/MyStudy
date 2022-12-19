
```
public int[][] merge(int[][] intervals) {
        boolean[] merged = new boolean[intervals.length];
        for (int i = 0; i < intervals.length; i++) {
            if (merged[i]) continue;//被去掉了
            for (int j = i + 1; j < intervals.length; j++) {

                if (intervals[i][1] > intervals[j][1]) {// i头大
                    if (intervals[j][1] >= intervals[i][0]) {//若j(小)头比i(大)尾大，则必定有交集

                        if (intervals[j][0] <= intervals[i][0]) {//若大尾>小尾，则是相交
                            intervals[j][1] = intervals[i][1];
                            merged[i] = true;
                            break;//将子集合标记删除，跳出这层循环
                        } else {
                            //否则，i必定是父集
                            intervals[j] = intervals[i];
                            merged[i] = true;
                            break;//将子集合标记删除，跳出这层循环
                        }
                    } else {
                        continue;
                    }
                } else if (intervals[j][1] >= intervals[i][1]) {// j头大
                    if (intervals[i][1] >= intervals[j][0]) {//若i(小)头比j(大)尾大，则必定相交
                        if (intervals[i][0] <= intervals[j][0]) {//若大尾>小尾，则是相交
                            intervals[j][0] = intervals[i][0];
                            merged[i] = true;
                            break;//将子集合标记删除，跳出这层循环
                        } else {
                            //则j一定是父亲
                            merged[i] = true;
                            break;//将子集合标记删除，跳出这层循环
                        }
                    } else {
                        continue;
                    }
                }
            }
        }
        //找出false的所有集合
        int count = 0;
        for (int i = 0; i < merged.length; i++) {
            if (!merged[i]) count++;
        }
        int[][] result = new int[count][2];
        int index = 0;
        for (int i = 0; i < merged.length; i++) {
            if (!merged[i]) {
                result[index] = intervals[i];
                index++;
            }
        }
        return result;
    }
```
