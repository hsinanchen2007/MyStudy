```
select e.lv transactions_count,nvl(e.visits_count,0) visits_count from
(select c.transactions_count, c.visits_count,nvl(c.mcnt,max(c.mcnt)over()) mcnt,d.lv
  from (select max(c.transactions_count) over() mcnt,
               c.transactions_count,
               c.visits_count
          from (select transactions_count, count(user_id) visits_count
                  from (select nvl(a.cnt, 0) transactions_count, b.user_id
                          from (select user_id, transaction_date, count(1) cnt
                                  from Transactions
                                 group by user_id, transaction_date) a,
                               visits b
                         where b.user_id = a.user_id(+)
                           and b.visit_date = a.transaction_date(+))
                 group by transactions_count) c) c,
       (select level - 1 lv from dual connect by level < 1000) d
 where c.transactions_count(+) = d.lv) e
 where e.lv <= e.mcnt
 order by e.lv asc
```
