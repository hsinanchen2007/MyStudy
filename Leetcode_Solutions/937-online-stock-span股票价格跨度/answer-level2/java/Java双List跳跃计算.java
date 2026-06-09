类似于动态规划,不难理解。(我dp太菜了，说错了请更正！)
<br>
思路：
1. `list`记录价格，`stepList`记录某天相对于其之前天数的跨度；
2. 当天跨度初始值为`int ans = 1`，因为最先对比前一天，所以初始对比天数为`int day = list.size() - 1;`；
3. 先对比前一天价格，如果price小于前一天，直接返回1，否则获取前一天的跨度，假设为`int step = stepList.get(day)`，天数往前跳`step`天(即`day -= stepList.get(day);`),跳跃后如果那天价格大于当前`price`，则返回`ans`,并记录到2个List里，否则继续循环操作此步骤；
4. 如果遍历结束了仍没找到，说明前面几天都比它小，ans为前一天跨度+1。
<br>
<br>
```java
public class StockSpanner {
    List<Integer> list;
    List<Integer> stepList;

    public StockSpanner() {
        list = new ArrayList<>();
        stepList = new ArrayList<>();
    }

    public int next(int price) {
        //第一天肯定是1
        if (list.size() == 0) {
            list.add(price);
            stepList.add(1);
            return 1;
        }

        int ans = 1;//跨度
        for (int day = list.size() - 1;day > -1;) {
            if (list.get(day) > price) {
                //如果跳跃后已经大于price，找到结果，存到list
                list.add(price);
                stepList.add(ans);
                return ans;
            }
            //跨度加上前一天的跨度
            ans += stepList.get(day);
            //天数往前跳跃
            day -= stepList.get(day);
        }
        list.add(price);
        stepList.add(ans);
        return ans;
    }
}
```
