```
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int[] tmpInterval = newInterval.clone();
        boolean insertFlag = false;
        List<int[]> result = new ArrayList<>();
        for (int[] interval : intervals) {
            if (!insertFlag && tmpInterval[1] < interval[0]) {
                result.add(tmpInterval);
                insertFlag = true;
            }
            if (!insertFlag && isOverlapping(tmpInterval, interval)) {
                tmpInterval = superimposed(tmpInterval, interval);
            } else {
                result.add(interval);
            }
        }
        if (!insertFlag) {
            result.add(tmpInterval);
        }
        return result.toArray(new int[0][0]);
    }

    private boolean isOverlapping(int[] intervalA, int[] intervalB) {
        if (intervalA[0] > intervalB[1] || intervalA[1] < intervalB[0]) {
            return false;
        } else {
            return true;
        }
    }

    private int[] superimposed(int[] intervalA, int[] intervalB) {
        int[] result = new int[2];
        result[0] = intervalA[0] < intervalB[0] ? intervalA[0] : intervalB[0];
        result[1] = intervalA[1] > intervalB[1] ? intervalA[1] : intervalB[1];
        return result;
    }
}
```