### 解题思路
筛选使用GROUP BY , 而不是order by；
子查询的筛选要使用HAVING函数，不能在group by直接操作；
不唯一要使用distinct函数；
最后要理解group by返回的的真正结果。大于5要使用count

### 代码

```mysql
# Write your MySQL query statement below
SELECT
    class
FROM courses
GROUP BY class 
HAVING COUNT(distinct(student))>=5
```