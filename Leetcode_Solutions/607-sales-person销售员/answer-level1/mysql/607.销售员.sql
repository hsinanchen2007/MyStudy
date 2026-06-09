注意：要查没有向公司'RED'销售任何东西的销售员，这时不能查询订单表中不是RED公司的记录，因为一个销售员会对应0条或多条的订单。

法1（子查询，先查出有向RED公司销售过的销售员id，再配合`not in`排除这些销售员）：
```MySQL
select `name`
from salesperson
where sales_id not in (select o.sales_id 
                       from orders o
                           left join company c on o.com_id = c.com_id
                       where c.`name` = 'RED');
```

法2（不使用子查询，[来源](https://leetcode-cn.com/problems/sales-person/solution/bu-shi-yong-not-inzi-cha-xun-de-zuo-fa-by-wang-xia/)）
```MySQL
select s.`name`
from salesperson s
    left join orders o on s.sales_id = o.sales_id
    left join company c on o.com_id = c.com_id
group by s.`name`
having sum(if(c.`name` = 'RED', 1, 0)) = 0;
```