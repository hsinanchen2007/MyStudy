# 代码
```java
class MyCalendarThree {
    TreeMap<Integer, Integer> tm;//记录时间点右侧的日程总数
    int res = 0;

    public MyCalendarThree() {
        tm = new TreeMap<>();
    }

    public int book(int start, int end) {
        int prvSum, nxtSum;
        Integer prv = tm.floorKey(start);//取出开始点左侧的键（含自身）
        res = Math.max(res, prvSum = prv == null ? 1 : tm.get(prv) + 1);
        prv = tm.floorKey(end);//取出结束点左侧的键（含自身）
        res = Math.max(res, nxtSum = prv == null ? 0 : tm.get(prv));
        tm.put(start, prvSum);//设定开始点日程总数
        tm.put(end, nxtSum);//设定结束点日程总数

        Integer iKy = tm.higherKey(start);//取出下一个检查点
        while (iKy != null && iKy < end) {//对开始点到结束点内的键，都加一
            res = Math.max(res, tm.merge(iKy, 1, (o_val, n_val) -> o_val + n_val));//都加一
            iKy = tm.higherKey(iKy);//取出下一个检查点
        }
        return res;
    }
}
```
