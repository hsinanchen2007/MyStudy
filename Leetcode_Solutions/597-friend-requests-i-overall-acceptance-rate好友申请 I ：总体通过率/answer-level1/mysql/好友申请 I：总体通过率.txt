#### 方法：使用 `round` 和 `isfull` [Accepted]

**想法**

统计通过的请求数并用它除总请求数。

**算法**

为了得到不同通过请求的数目，我们可以从 **request_accepted** 表中进行查询。
```sql []
select count(*) from (select distinct requester_id，accepter_id from request_accepted；
```
使用相同的办法，我们可以从 **friend_request** 表中得到总请求数。
```sql []
select count(*) from (select distinct sender_id，send_to_id from friend_request；
```

最后，将两个数字相除并取整 [`round`](https://dev.mysql.com/doc/refman/5.7/en/mathematical-functions.html#function_round) 到 2 位小数，以得到想要的通过率。

但是！当 **friend_request** 表为空时，总请求数，也就是分母，有可能为 `0`。所以我们需要使用 [`ifnull`](https://dev.mysql.com/doc/refman/5.7/en/control-flow-functions.html#function_ifnull) 函数来处理这种特殊情况。

```sql []
select
round(
    ifnull(
    (select count(*) from (select distinct requester_id, accepter_id from request_accepted) as A)
    /
    (select count(*) from (select distinct sender_id, send_to_id from friend_request) as B),
    0)
, 2) as accept_rate;
```