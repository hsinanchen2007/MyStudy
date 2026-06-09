select distinct p.product_id, p.product_name from product p
inner join sales s
on p.product_id = s.product_id
where p.product_id not in

(
    select p.product_id from product p
    inner join sales s
    on p.product_id = s.product_id

    where sale_date < '2019-01-01' or sale_date > '2019-03-31'
)

order by p.product_id