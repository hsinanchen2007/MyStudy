### 解题思路
直接联表查询，最后having再筛一遍 搞定~
### 代码

```mysql
# Write your MySQL query statement below


select b.book_id,b.name from Books b left join Orders o on b.book_id = o.book_id
where b.available_from < '2019-05-23' 
 group by b.book_id 
 having sum(case when datediff('2019-06-23',o.dispatch_date ) < 365 then o.quantity else 0 end) < 10
```