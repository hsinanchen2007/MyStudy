#### 方法一：`GROUP BY` 和 `DISTINCT`

**思路**

1. 使用 `COUNT` 函数计算用户的数量。因为该表没有主键，可能包含重复数据，所以需要在此基础上使用 `DISTINCT` 去重：`COUNT(DISTINCT user_id）`。
2. 统计**截至** 2019-07-27，近 30 天的每日活跃用户，所以需要使用 `WHERE` 过滤数据，可以使用两种办法（注意是**截至**不是**截止**）：
    1. 计算出第一天，使用 `BETWEEN` ：`WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'`。
    2. 使用 `datediff()` 函数，计算当天与最后一天的差值：`WHERE datediff('2019-07-27',activity_date) < 30`。
3. 使用 `GROUP BY` 按天聚合。

**代码**

```Mysql [ ]
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE datediff('2019-07-27',activity_date) < 30
-- WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY activity_date
```