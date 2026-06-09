### 解题思路
这题的难点在于不能用where来筛选订单，否则有些buyer_id无法显示。既然如此
1 我们用case when把所有非2019的订单都变成0，这样做group的时候相加的就是2019年的订单数量，避免了需要再用一次子查询创建临时表，然后再做left join。
2 ifnull还是需要用的，不然会报错。

### 代码


select u.user_id as buyer_id,
        u.join_date,
        ifnull(sum(case when extract(year from order_date) = '2019' then 1 else 0 end) , 0) as orders_in_2019
from Users u 
left join Orders o 
on u.user_id = o.buyer_id
group by u.user_id
















```