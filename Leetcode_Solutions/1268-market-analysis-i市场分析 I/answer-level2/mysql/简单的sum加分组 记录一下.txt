### 解题思路
刚开始会被item表迷惑，也搞不懂user_id和buyer_id的关系，理顺了就很简单。。。。 sum里面用公共sql函数判断一下，然后按照用户id分组就OK了 

### 代码

```mysql
# Write your MySQL query statement below
select user_id `buyer_id`,u.join_date,sum(case when o.order_date >= '2019-01-01' then 1 else 0 end) as `orders_in_2019` from Users u left join Orders o on u.user_id = o.buyer_id group by u.user_id
```