#### 方法：使用 `GROUP BY` 和 `COUNT` [Accepted]

**想法**

为了判断一个值在某一列中是不是唯一的，我们可以使用 `GROUP BY` 和 `COUNT`。

**算法**

检查每一个 **TIV_2015** 是否是唯一的，如果不是唯一的且同时坐标是唯一的，那么这条记录就符合题目要求。应该被统计到答案中。

**MySQL**

```sql [-Sql]
SELECT
    SUM(insurance.TIV_2016) AS TIV_2016
FROM
    insurance
WHERE
    insurance.TIV_2015 IN
    (
      SELECT
        TIV_2015
      FROM
        insurance
      GROUP BY TIV_2015
      HAVING COUNT(*) > 1
    )
    AND CONCAT(LAT, LON) IN
    (
      SELECT
        CONCAT(LAT, LON)
      FROM
        insurance
      GROUP BY LAT , LON
      HAVING COUNT(*) = 1
    )
;
```
>提示：连接 **LAT** 和 **LON** 为一个整体，以表示坐标信息。

注意：这两条要求需要不分顺序同时满足，所以如果你想要先用规则 1 来筛选一遍数据，然后再用规则 2 来筛选，会得到错误的结果。

拿下面的样例输入作为例子，在用第一条规则筛选一遍数据之后数据集会变成下面的样子。

| PID | TIV_2015 | TIV_2016 | LAT | LON |
|-----|----------|----------|-----|-----|
| 1   | 10       | 5        | 10  | 10  |
| 3   | 10       | 30       | 20  | 20  |
| 4   | 10       | 40       | 40  | 40  |

然后第二条规则不会把这个数据集的任何信息筛除出去。所以结果变成了 75 （5+30+40），这显然是错误的，因为 PID 为 '3' 的坐标与被规则 1 筛除记录的坐标其实是一样的。

| PID | TIV_2015 | TIV_2016 | LAT | LON |
|-----|----------|----------|-----|-----|
| 2   | 20       | 20       | 20  | 20  |
| 3   | 10       | 30       | 20  | 20  |
