### 解题思路
1. 使用 mod 函数，除以2取余是否不等于0，来判断是不是奇数

### 代码
```oraclesql
select id, movie, description, rating
from cinema
where description != 'boring'
  and mod(id,2) != 0
order by rating desc
```