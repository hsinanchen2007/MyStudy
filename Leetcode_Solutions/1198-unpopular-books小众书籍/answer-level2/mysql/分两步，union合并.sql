本题有一个陷阱，销量小于10的书籍还包括没有销量的那部分，所以分两步

第一步，找出销量小于10的书。使用join会过滤掉没有销量的书。
```
select
b.book_id,
b.name
from books b
join orders o on b.book_id=o.book_id
where b.available_from < '2019-05-23'
and o.dispatch_date between '2018-06-23' and '2019-06-23'
group by b.book_id
having sum(o.quantity)<10
```

第二步，找出没有销量的书。
```
select
book_id,
name
from books
where available_from < '2019-05-23'
and book_id not in (select distinct book_id from orders where dispatch_date between '2018-06-23' and '2019-06-23')
```

最后用union合并。
```
select
b.book_id,
b.name
from books b
join orders o on b.book_id=o.book_id
where b.available_from < '2019-05-23'
and o.dispatch_date between '2018-06-23' and '2019-06-23'
group by b.book_id
having sum(o.quantity)<10

union 

select
book_id,
name
from books
where available_from < '2019-05-23'
and book_id not in (select distinct book_id from orders where dispatch_date between '2018-06-23' and '2019-06-23')
;
```
