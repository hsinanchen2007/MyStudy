### 解题思路
INNER JOIN（内连接,或等值连接）：获取两个表中字段匹配关系的记录。也可以省略 INNER使用JOIN,效果一样
LEFT JOIN（左连接）：获取左表所有记录，即使右表没有对应匹配的记录。
RIGHT JOIN（右连接）： 与 LEFT JOIN 相反，用于获取右表所有记录，即使左表没有对应匹配的记录。
语法：
selct * from table_a  inner/left/right/join table_b on 条件

### 代码

```mysql
# Write your MySQL query statement below
select a.FirstName, a.LastName, b.City, b.State
from Person a
left join  Address b
on a.PersonId = b.PersonId
```