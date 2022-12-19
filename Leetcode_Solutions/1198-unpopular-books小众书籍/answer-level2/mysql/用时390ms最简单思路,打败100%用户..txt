
一、先从Orders表中提取dispatch_date的所有信息，并命名为tb1
  (select * from orders
   where dispatch_date > '2018-06-23') as tb1

二、再从tb1中提取那些销量大于等于10的book_id并命名为tb2
select book_id from
                    (select book_id ,sum(quantity)
                    from (select * from orders
                          where dispatch_date > '2018-06-23') as tb1
group by book_id
having sum(quantity)>=10) as tb2)

三、从books表中选取book_id不在tb2中，并且发行时间available_from不在一个月以内的book_id，name
# Write your MySQL query statement below(最终答案)
select book_id,name
from books
where book_id not in (select book_id from
                                        (select book_id ,sum(quantity)
                                        from (select * from orders
                                              where dispatch_date > '2018-06-23') as tb1
                      group by book_id
                      having sum(quantity)>=10) as tb2)
and available_from <'2019-05-23';