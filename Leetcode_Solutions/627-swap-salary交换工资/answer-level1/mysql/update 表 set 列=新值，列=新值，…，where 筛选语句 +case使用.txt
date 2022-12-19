### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
update  salary 
set sex =
case sex
when 'm' then 'f'
else 'm'
end;
```