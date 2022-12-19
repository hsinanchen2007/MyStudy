    /**
     * 这题本人的解题思路与Q45跳跃游戏II一致，这里的区间的起始点相当于起跳的下标，区间终点相当于跳的最远距离。
     * 只是这题需要做一个去重处理以及判断无法跳到终点。
     * 1. 区间去重，在起始相同的情况下保留跨对最长的区间
     * 2. 从时间0开始寻找下一个元素即在跳跃范围内寻找下一个跳的最远的下标。如果跳到终点就返回终点位置
     * 3. 如果下一个跳跃点和当前一样，则表示无法跳到终点
     */
    public int videoStitching(int[][] clips, int T) {
        // key: 起始时间，value: 最晚的结束时间
        Map<Integer, Integer> intervalMap = new HashMap<>();

        for (int[] interval : clips) {
            if (interval[0] < T) {
                intervalMap.put(interval[0], Math.max(interval[1], intervalMap.getOrDefault(interval[0], 0)));
            }
        }

        int count = 0;
        int idx = 0;
        while (idx < T) {
            count++;
            int temp = getNextIndex(idx, intervalMap, T);
            if (temp == idx) {
                return -1;
            } else {
                idx = temp;
            }
        }

        return count;
    }

    private int getNextIndex(int idx, Map<Integer, Integer> intervalMap, int T) {
        if (intervalMap.getOrDefault(idx, 0) >= T) return T;

        int furthest = 0;
        int furIdx = idx;
        for (int i = idx + 1; i <= Math.min(intervalMap.getOrDefault(idx, 0), T); i++) {
            int furVal = intervalMap.getOrDefault(i, 0);
            if (furVal > furthest) {
                furthest = furVal;
                furIdx = i;
            }
        }
        return furIdx;
    }