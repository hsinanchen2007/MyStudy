### 解题思路
一个是上架日期，限制时间是 2019-05-23 
一个是最近一年，限制时间是 2018-06-23

要以 books 作为主表去关联，因为去年一本书都没有卖出去的要算卖出去 0 本
如果后面没有这样一个判断的话， quantitiy 会是 null，不会被 sum


### 代码

```mysql
# Write your MySQL query statement below






select tmp1.book_id,tmp1.name
from(
    select b.book_id,b.name,tmp.quantity
    from (
        select o.book_id,o.quantity
        from Orders o 
        where o.dispatch_date>"2018-06-23" 
    ) tmp 
    right join Books b 
    on tmp.book_id = b.book_id 
    where b.available_from<"2019-05-23"
) tmp1
group by tmp1.book_id
having sum(if (isnull(tmp1.quantity),0,tmp1.quantity))<10
```