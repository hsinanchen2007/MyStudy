#### 方法：将 *requester_id* 和 *accepter_id* 联合起来 [Accepted]

**算法**

成为朋友是一个双向的过程，所以如果一个人接受了另一个人的请求，他们两个都会多拥有一个朋友。

所以我们可以将 *requester_id* 和 *accepter_id* 联合起来，然后统计每个人出现的次数。

```sql []
select requester_id as ids from request_accepted
union all
select accepter_id from request_accepted;
```

>注意：这里我们应该使用 `union all` 而不是 `union` ，因为 `union all` 即使遇到重复的记录也都会保存下来。

拿样例举例，输出应该是：

| ids |
|-----|
| 1   |
| 1   |
| 2   |
| 3   |
| 2   |
| 3   |
| 3   |
| 4   |

然后我们可以用问题 [580. 统计各专业学生人数](https://leetcode-cn.com/problems/count-student-number-in-departments/) 中一样的方法获得出现次数最多的 `ids`。


```sql []
select ids as id, cnt as num
from
(
select ids, count(*) as cnt
   from
   (
        select requester_id as ids from request_accepted
        union all
        select accepter_id from request_accepted
    ) as tbl1
   group by ids
   ) as tbl2
order by cnt desc
limit 1
;
```
