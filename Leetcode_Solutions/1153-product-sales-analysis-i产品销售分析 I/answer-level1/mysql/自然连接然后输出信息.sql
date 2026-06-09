### 解题思路
直接自然连接然后输出要找的信息，不过用时挺长的，不知道是什么原因，自然连接应该效率不差。

### 代码

```mysql
# Write your MySQL query statement below
select product_name, year, price
from Sales natural join Product;
```