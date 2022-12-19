### 解题思路
主要是要挑出最小的，当只要一个值的时候可以使用排序然后用 limit 的方式，也可以使用 min 函数


### 代码

```mysql
# Write your MySQL query statement below

select
	s1.product_id product_id,
	s1. year first_year,
	s1.quantity quantity,
	s1.price price
from
	(
		select
			s.product_id,
			min(year) first
		from
			Sales s
		group by
			s.product_id
	) tmp
left join Sales s1 on tmp.product_id = s1.product_id
and tmp. first = s1. year
```