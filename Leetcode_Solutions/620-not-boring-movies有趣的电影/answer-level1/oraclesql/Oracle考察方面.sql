### 解题思路
此题主要就是记住mod函数就很简单了

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select * from cinema a where a.description <>'boring' and mod(a.id,2)=1 order by a.rating desc;
```