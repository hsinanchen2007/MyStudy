### 解题思路
update更新字段语法：
update table_name set column1='value1',column2='value2',......


### 代码

```mysql
# Write your MySQL query statement below
update salary
set sex=if(sex='f','m','f')
```