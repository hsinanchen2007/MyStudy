### 解题思路
此处撰写解题思路
1、读题-交换，不可出现select  case when
2、学习-if（x,t,f）,sqlserver 不支持

### 代码

```mssql
/* Write your T-SQL query statement below */
UPDATE  salary
SET     sex = ( CASE sex
                  WHEN 'm' THEN 'f'
                  ELSE 'm'
                END );
```