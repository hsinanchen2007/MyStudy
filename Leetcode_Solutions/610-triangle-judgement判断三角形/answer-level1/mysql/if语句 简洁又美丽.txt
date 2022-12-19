执行用时 :246 ms, 在所有 MySQL 提交中击败了100.00%的用户
内存消耗 :N/A
```
select *,
if((x + y <= z or x + z <= y or y + z <= x), "No", "Yes") as triangle
from triangle;
```
