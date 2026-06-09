### 解题思路
1. 不加上 ManagerId 为空的筛选条件, 则执行时间会最少也要1秒.
2. 自连接和该SQL运行速度差不多
3. 个人觉得LeetCode的测试速度很不稳,同样的code不同时间测试会有很大的跨度, 如自连接的写法有过585ms也有3101ms的情况

### 代码

内连接情况
```oraclesql
/* Write your PL/SQL query statement below */

SELECT emp.name AS "Employee" 
FROM employee emp
INNER JOIN employee mana
ON emp.ManagerId = mana.id
WHERE emp.salary>mana.salary
AND emp.ManagerId is not null
;
```

自连接情况
```oraclesql
SELECT emp.name AS "Employee" 
FROM employee emp
,employee mana
WHERE emp.ManagerId = mana.id
AND emp.salary>mana.salary
;
```