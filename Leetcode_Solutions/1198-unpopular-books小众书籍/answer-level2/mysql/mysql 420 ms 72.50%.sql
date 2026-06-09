### 解题思路
题目没看清，越写越麻烦。
大致思路用补集


### 代码

```mysql
# Write your MySQL query statement below

select book_id,name
from books
where book_id not in (
select o.book_id
from orders o left join books b on o.book_id = b.book_id
where (dispatch_date>='2018-06-23') 
group by o.book_id
having sum(quantity)>=10
) and (datediff('2019-06-23',available_from)>30)






```