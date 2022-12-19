### 解题思路
1. 利用`GROUP BY...HAVING`进行条件限制，从而挑选出满足条件的结果；
2. 注意`DISTINCT`的使用是为了防止一个学生对应的多节相同课程；

### 代码

```mysql
# Write your MySQL query statement below
SELECT class FROM courses GROUP BY class HAVING COUNT(DISTINCT student) > 4;
```