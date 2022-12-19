
```pgsql
 GROUP BY 语法

SELECT column_name, function(column_name)
FROM table_name
WHERE column_name operator value
GROUP BY column_name; 

```
**GROUP BY 语句根据一个或多个列对结果集进行分组。**

在分组的列上我们可以使用 COUNT, SUM, AVG,等函数。 

**AVG()**
求平均值

**COUNT(*)**
对表中行数进行计数

**COUNT(字段名)**
对特定列有数据的行进行计数

**SUM()**
可以对单个列求和，也可以对多个列运算后求和

```sql
SELECT
	Email 
FROM
	( 
        SELECT 
        Email, count(*) num 
        FROM 
        Person
         GROUP BY Email 
        ) 
        AS count_table 

    
WHERE
	num > 1;
```
