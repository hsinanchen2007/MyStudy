方法：$$总体通过率 = \frac{好友通过数}}{好友申请数}$$，分别统计好友通过数与好友申请数即可。

```MySQL
select 
    round(
        ifnull(
            (select count(distinct requester_id, accepter_id) from request_accepted)
            /
            (select count(distinct sender_id, send_to_id) from friend_request)
        , 0)
    , 2) accept_rate;
```

    对于计算字段，使用`ifnull`以及`round`进行规范是极为必要的。