*我是按照自己对题目主观理解进行的解构，如有可优化的步骤还请各位大神斧正*
步骤1.题干描述**会存在重复行**，所以先把数据进行一遍去重操作，保证每个用户在同一天内浏览过的文章至多出现一次。
```
SELECT DISTINCT
    *
FROM
    Views;
```
步骤2.查询要求是**找出在同一天阅读至少两篇文章的人**，理解为在同一天之内用户要至少有两行数据，可以对步骤1中拿到的结果集按照`viewer_id`和`view_date`重新分组，还得将分组结果进行一次过滤操作，过滤条件就是`COUNT() >= 2`,最后进行排序。
```
SELECT DISTINCT
    viewer_id AS id
FROM
    (SELECT DISTINCT
        *
    FROM
        Views) AS t
GROUP BY viewer_id , view_date
HAVING COUNT(viewer_id) >= 2
ORDER BY viewer_id , view_date;
```