### 解题思路
1. 学习了在 update 中使用 case-when

### 代码
```oraclesql
update salary
set sex = case sex when 'f' then 'm' else 'f' end
```