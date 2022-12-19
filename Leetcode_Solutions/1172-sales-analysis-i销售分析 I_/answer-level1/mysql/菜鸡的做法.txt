论菜鸡的自我修养
这是我们菜鸡的做法，略繁琐，emmm，但是容易懂(吧
```
-- 首先，要统计每个销售员的总业绩
-- 这里只是为了看一下结果而已，属于中间过程
select  seller_id, sum(price) as yeji from  Sales  group by  seller_id;

-- 然后找到这里面最高的业绩
select sum(price) as ye_ji from  Sales  group by  seller_id order by ye_ji desc limit 1;

-- 然后找到原始表中业绩与这个最高业绩相等的seller_id
select seller_id from Sales group by seller_id having sum(price) = (select sum(price) as ye_ji from  Sales  group by  seller_id order by ye_ji desc limit 1);
```