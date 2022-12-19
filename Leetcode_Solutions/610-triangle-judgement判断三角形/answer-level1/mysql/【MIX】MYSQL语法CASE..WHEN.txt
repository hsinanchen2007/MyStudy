### 解题思路
CASE WHEN语句

### 代码

```mysql
# Write your MySQL query statement below
# case when 语法使用
SELECT x, y, z,
CASE
    WHEN x+y>z AND x+z>y AND y+z>x THEN 'Yes'
    ELSE 'No'
END
AS 'triangle'
FROM triangle;
```