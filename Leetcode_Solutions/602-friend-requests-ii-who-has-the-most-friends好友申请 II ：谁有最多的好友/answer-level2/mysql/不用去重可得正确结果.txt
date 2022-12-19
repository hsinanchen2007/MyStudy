[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

好友关系是相互的。A加过B好友后，A和B相互是好友了。

那么，将表中的字段requester_id和accepter_id交换后，再拼接起来。能找出全部的好友关系。

应用UNION运算符。
```
SELECT column_list
UNION [DISTINCT | ALL]
SELECT column_list
```
即使不用DISTINCT关键字，UNION也会删除重复行。ALL不会删除重复行。

结果命名为表A。
```
(
    select R1.requester_id as rid,R1.accepter_id as aid
    from request_accepted as R1
    UNION all
    select R2.accepter_id as rid,R2.requester_id as aid
    from request_accepted as R2
) as A
```
按rid分组，计算每组的好友个数，并按好友个数降序，取第一个人。
```
select rid as `id`,count(aid) as `num`
from
(
    select R1.requester_id as rid,R1.accepter_id as aid
    from request_accepted as R1
    UNION all
    select R2.accepter_id as rid,R2.requester_id as aid
    from request_accepted as R2
) as A
group by rid
order by num desc
limit 0,1
```