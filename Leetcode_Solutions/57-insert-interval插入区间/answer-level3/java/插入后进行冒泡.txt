
```
    /**
     * 先把新增的区间放入到原先的区间中，然后进行一次冒泡
     * 时间复杂度：O(n)
     * 空间复杂度：O(n + m)，m是结果的长度
     * @param intervals
     * @param newInterval
     * @return
     */
    private static int[][] insert2(int[][] intervals, int[] newInterval) {
        int[][] addArr = new int[intervals.length + 1][2];
        boolean add = false;
        int addIndex = 0;
        // 添加新增的区间
        for (int[] interval : intervals) {
            if(interval[0] > newInterval[0]){
                if(!add) {
                    add = true;
                    addArr[addIndex++] = newInterval;
                }
            }
            addArr[addIndex++] = interval;
        }
        if(!add){
            addArr[addArr.length-1] = newInterval;
        }
        //合并次数
        int mergeCount = 0;
        for (int i = 0; i < addArr.length - 1 ; i++) {
            if(addArr[i][1] >= addArr[i + 1][0]){
                addArr[i + 1][0] = addArr[i][0];
                addArr[i + 1][1] = Math.max(addArr[i][1],addArr[i + 1][1]);
                //小的区间置空
                addArr[i] = null;
                mergeCount++;
            }
        }
        int[][] res = new int[addArr.length - mergeCount][];
        int resIndex = 0;
        for (int[] ints : addArr){
            if(ints != null){
                res[resIndex++] = ints;
            }
        }
        return res;
    }
```
