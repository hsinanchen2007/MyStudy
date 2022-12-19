![image.png](https://pic.leetcode-cn.com/b8c00f37fb5892799bb53dc719d1fe4feac1bb4fa607851af0f7bb92cfa9b6e0-image.png)

### 首先分两块找
1. 第一块是2019-08-16之前（含2019-08-16）修改过价格的商品与日期
2. 第二块则是2019-08-16之前没有修改古价格商品与日期
3. 将两者进行union

### 连接原products表
条件为`p.product_id = n.product_id and p.change_date = n.last_date`
其中 p代表products表，n代表union后的结果表
取出product_id 与 价格，**在价格这一列使用if函数**

### 代码

```mysql
# Write your MySQL query statement below
select n.product_id, 
       if(n.last_date > '2019-08-16', 10, p.new_price) as "price"
  from products p, 
       (select product_id, max(change_date) as "last_date"
          from products
         where change_date <= '2019-08-16'
         group by product_id
        union
        select product_id, min(change_date) as "last_date"
          from products
         group by product_id
        having min(change_date) > '2019-08-16') n
 where p.product_id = n.product_id and p.change_date = n.last_date;

 


```