### 解题思路
分别计算通过、申请人数（记得去重），相除即可

### 代码

```mssql
/* Write your T-SQL query statement below */
select isnull(cast((select sum(c2) from (select requester_id,count(distinct accepter_id) c2 from request_accepted group by requester_id) t)*1.0/
(select sum(c1) from (select sender_id,count(distinct send_to_id) c1 from friend_request group by sender_id) t) as decimal(10,2)),0) accept_rate
```