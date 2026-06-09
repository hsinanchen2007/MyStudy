

 WITH 
    e --建立一个查询 购买S8产品 且去重用户 的临时表
    AS (select distinct s.buyer_id  from product t left join sales s on t.product_id = s.product_id where              1=1 and t.product_name='S8'),
    i --建立一个查询 购买iphone产品 且去重用户 的临时表
    AS (select distinct  s.buyer_id  from product t left join sales s on t.product_id = s.product_id where             1=1 and t.product_name='iPhone')
----计算两个查询表的差集
select e.buyer_id from e
 minus
select i.buyer_id from i