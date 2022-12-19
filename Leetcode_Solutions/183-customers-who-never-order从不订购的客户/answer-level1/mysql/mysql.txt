![图片.png](https://pic.leetcode-cn.com/3a5e4a7c2c8c10f531086c0b576f6fedccf908c339ccdfe797dae0fba31495ba-%E5%9B%BE%E7%89%87.png)

```
select Name as Customers from Customers where Id not in (select CustomerId from Orders);
```
