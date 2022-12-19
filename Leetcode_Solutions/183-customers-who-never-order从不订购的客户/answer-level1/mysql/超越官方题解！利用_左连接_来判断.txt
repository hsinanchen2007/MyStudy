## 思路
+ 将两张表join一下
+ 找到join后顾客没有购物的
## 代码
```SQL
select A.Name as Customers
from Customers A left join Orders B
on A.Id = B.CustomerId
where B.Id is null
```

+ Customer A　的意思就是给Customer起个别名叫Ａ，方便后面写代码方便，Orders　B 同理
+ left join　是左连接，意思是左边的全保留，如果左边的和右边的不符合on的条件，那么左边对应右边的列自动为null
+ 效率比官方题解高很多