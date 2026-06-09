
题目少了个条件，销量要在距今一年内<10,并且不考虑 上架（available from）距今 
不满一个月 的书籍。并且 假设今天是 2019-06-23 
所以5是可以通过的，5的总销量>=10但是并不在一年内
DATE_SUB() 函数从日期减去指定的时间间隔。

select
  book_id,
  name
from Books b
where
  b.book_id not in ( #book_id为空也要查出来
    select
      book_id
    from orders
    where
      dispatch_date >= date_sub('2019-06-23', interval 1 year) #一年之内
    group by
      book_id
    having
      sum(quantity) >= 10 #总订单量>=10
  )
  and b.available_from < date_sub('2019-06-23', interval 1 MONTH)#上架距今超过一个月的书籍
