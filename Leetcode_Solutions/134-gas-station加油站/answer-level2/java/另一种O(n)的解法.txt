```
/**
     * 思路：
     * a[i]=gas[i]-cost[i]的正负决定了能否走到下一站。另外，若存在一个加油站可以走一圈的话，那么sum(a[i])必然
     * 大于等于0，否则，它是铁定绕不了一圈的。如果满足sum(a[i])>=0那么一定存在一个加油站可以绕一圈。
     *
     * 对于存在一个加油站可以绕一圈的数组a，如何找到这个起点呢？使用cnt记录走过的a[i]的和，start标记起点，
     * 如果遇到cnt<0则此start位置不是起点，换成下一个位置它指向位置i，cnt总是累加[start,i-1]（i-1<start是合理的
     * 它是个环形的）。当i==start时，证明绕了一圈，返回start即可。
     */
    // 61.77% 1ms(中文) 100% 0ms(英文)
    public int canCompleteCircuit(int[] gas, int[] cost) {
        if (gas.length == 0) return -1;
        if (gas.length == 1) return gas[0]-cost[0] >= 0 ? 0 : -1;
        int[] a = new int[gas.length];
        int flag = 0;
        for (int i = 0; i < gas.length; i++) {
            a[i] = gas[i] - cost[i];
            flag += a[i];
        }
        if (flag < 0) return -1;
        int start = 0, i, cnt;
        for (i = start+1, cnt = a[start]; i != start; i = (++i) % gas.length) {
            if (cnt < 0) {
                cnt = a[i];
                start = i;
            } else {
                cnt += a[i];
            }
        }
//        return cnt >= 0 ? start : -1;
        return start;
    }
```
如果对您有帮助，给个赞吼^_^