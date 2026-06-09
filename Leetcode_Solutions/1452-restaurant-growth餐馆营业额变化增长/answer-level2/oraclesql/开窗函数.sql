select to_char(visited_on,'yyyy-MM-dd') visited_on, amount, round(amount / 7, 2) average_amount
  from (select visited_on,
               sum(amount) over(order by visited_on rows between 6 preceding and current row) amount
          from (select visited_on, sum(amount) amount
                  from Customer
                 group by visited_on))
 where visited_on in
       (select distinct visited_on
          from Customer
         where to_number(to_char(visited_on, 'yyyyMMdd')) - 6 >=
               (select to_number(to_char(min(visited_on), 'yyyyMMdd')) from Customer)
         )