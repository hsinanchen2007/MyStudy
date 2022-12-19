### 解题思路
第一次见这个，注意点：case后面接要修改的列名；最后要有end

### 代码

```mysql
# Write your MySQL query statement below
update salary set sex= (case sex when 'm' then 'f'
else 'm' end);
```