[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_57_insert.java)

```java
    /**
     * 前提：
     * 对于数字和一个区间的关系只有三种，在区间内，区间前，区间后
     * <p>
     * 解题思路：
     * 1.遍历intervals，拿到item后先判断，确定newInterval的起始和终止位置和区间的关系si,sFind,ei,eFind
     * 2.si,ei代表和目前区间的位置关系，-1代表不在区间范围内（比最后一个区间都大）
     * 3.sFind，eFind代表是否在区间内，true表示区间内，false表示区间前（区间后可以转换为下一个区间的区间前）
     * 4.根据si,sFind,ei,eFind去拼装结果
     * 5.if:si == -1 && ei == -1 ==> 最后加入
     * 6.else if:si == ei ==> 中间插入或者更新某个区间
     * 7.else ==> 合并区间
     *
     * @param intervals
     * @param newInterval
     * @return
     */
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int[][] retArr;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int si = -1, ei = -1;
        boolean sFind = false, eFind = false;
        for (int i = 0; i < intervals.length; i++) {
            int[] item = intervals[i];
            int itemStart = item[0];
            int itemEnd = item[1];
            if (si == -1) {
                if (newStart <= itemEnd) {
                    si = i;
                    if (newStart >= itemStart) {
                        sFind = true;
                    }
                }
            }
            if (ei == -1) {
                if (newEnd <= itemEnd) {
                    ei = i;
                    if (newEnd >= itemStart) {
                        eFind = true;
                    }
                }
            }
            if (si != -1 && ei != -1) {
                break;
            }
        }
        //插入or合并区间
        if (si == -1 && ei == -1) {
            //插入最后
            retArr = Arrays.copyOf(intervals, intervals.length + 1);
            retArr[intervals.length] = new int[]{newStart, newEnd};
        } else if (si == ei) {
            int[] temp = new int[2];
            if (!sFind) {
                temp[0] = newStart;
            } else {
                temp[0] = intervals[si][0];
            }
            if (!eFind) {
                temp[1] = newEnd;
            } else {
                temp[1] = intervals[ei][1];
            }
            if (!sFind && !eFind) {
                //新插入一个
                retArr = new int[intervals.length + 1][];
                int insetI = 0;
                for (int i = 0; i < intervals.length; i++) {
                    if (i == si) {
                        retArr[insetI] = temp;
                        insetI++;
                    }
                    retArr[insetI] = intervals[i];
                    insetI++;
                }
            } else {
                intervals[si] = temp;
                retArr = Arrays.copyOf(intervals, intervals.length);
            }
        } else {
            //合并区间
            int skipStartI, skipEndI;
            int[] temp = new int[2];
            if (sFind) {
                temp[0] = intervals[si][0];
                skipStartI = si;
            } else {
                temp[0] = newStart;
                skipStartI = si;
            }
            if (eFind) {
                temp[1] = intervals[ei][1];
                skipEndI = ei;
            } else {
                temp[1] = newEnd;
                if (ei == -1) {
                    skipEndI = intervals.length - 1;
                } else {
                    skipEndI = ei - 1;
                }
            }
            int skip = skipEndI - skipStartI;
            retArr = new int[intervals.length - skip][];
            for (int i = 0; i < intervals.length; i++) {
                if (i < skipStartI) {
                    retArr[i] = intervals[i];
                } else if (i >= skipStartI && i <= skipEndI) {
                    if (i == skipStartI) {
                        retArr[skipStartI] = temp;
                    }
                } else {
                    retArr[i - skip] = intervals[i];
                }
            }
        }


        return retArr;
    }

```