### 解题思路
此处撰写解题思路
1、读题-超过5名选课 group by having
2、多角度-重复数据，开始没考虑
3、学习-俩表关联其中一个去重;with as 临时表；
4、优化-count 里面可以用去重distinct 哇哦学习了

### 代码

```mssql
/* Write your T-SQL query statement below */

SELECT  class
FROM    courses
GROUP BY class
HAVING  COUNT(distinct student) > 4;
```