```
class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int costOne = costs[0];
        int costEleven = costs[1];
        int costThirsty = costs[2];
        int[] dayCost = new int[366];
        int dayIndex = 0;
        for (int i = 1; i < 366 && dayIndex < days.length; i++) {
            if (i < days[dayIndex]) {
                //如果当天没有旅游，就是前一天的开销
                dayCost[i] = dayCost[i-1];
            } else {
                /**
                 * 如果今天旅游了，则考虑一下今天买一天票的花销，7天前买了7天票的花销，以及30天前买了30天票的花销，
                 * 取最小值
                 */
                dayCost[i] = Math.min(dayCost[i-1] + costOne, dayCost[i-7 > -1 ? i-7 : 0] + costEleven);
                dayCost[i] = Math.min(dayCost[i], dayCost[i-30 > -1 ? i-30 : 0] + costThirsty);
                dayIndex ++;
            }
        }
        return dayCost[days[days.length-1]];
    }
}
```
