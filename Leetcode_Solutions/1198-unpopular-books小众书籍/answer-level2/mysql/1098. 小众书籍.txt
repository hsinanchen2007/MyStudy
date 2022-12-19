### 解题思路
此处撰写解题思路
题目的要求
1.过去一年内
2.少于10本
3.排除上市不到一个月的


### 代码

```mysql
# Write your MySQL query statement below

select b.book_id,b.name 
from Books b
where datediff('2019-06-23',b.available_from)>30
and  b.book_id not in(
    select book_id from Orders
    where datediff('2019-06-23',dispatch_date ) <=365
    group by book_id
    having sum(quantity) >=10
)
```