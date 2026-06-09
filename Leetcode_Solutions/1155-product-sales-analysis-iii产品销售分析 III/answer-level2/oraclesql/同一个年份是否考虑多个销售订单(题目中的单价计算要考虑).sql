select product_id,
       year as first_year,
       sum(quantity) as quantity,
       sum(quantity * price) / nvl(sum(quantity), 1) as price
  FROM (SELECT product_id, year, quantity, price
          from (select product_id,
                       year as year,
                       quantity,
                       price,
                       rank() over(partition by product_id order by year asc) rn
                  from Sales) t
         where rn = 1)
 group by product_id, year ;