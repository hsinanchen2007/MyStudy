题目中「经理之间的间接关系不超过3个经理」的约束条件，简化了结果集，使得硬编码三次关联关系这种解法可行。假设，没有「关系不超过3个经理」这一约束又该如何呐？ 下面介绍一种 PostgresSQL 中的骚操作「递归CTE」。

在 PG 中构造 CTE 时加上关键字 `recursive` 就可以在构造 SQL 中递归的引用自己，特别适合描述本题中的树状结构：

```sql
with recursive org_tree as (
    select employee_id, employee_id::varchar as relation, 0 as level
    from employees where employee_id = 1
    union all
    select t1.employee_id, concat(t1.employee_id, '->', t2.relation), t2.level + 1
    from employees t1,
         org_tree t2 -- 重点在这里，关联 CTE 自己
    where t1.manager_id = t2.employee_id
    and t1.employee_id != t1.manager_id
)
select * from org_tree
```

可以得到：
| employee\_id | relation | level |
| :--- | :--- | :--- |
| 1 | 1 | 0 |
| 2 | 2-&gt;1 | 1 |
| 77 | 77-&gt;1 | 1 |
| 4 | 4-&gt;2-&gt;1 | 2 |
| 7 | 7-&gt;4-&gt;2-&gt;1 | 3 |

然后简单的使用一行 SQL
```sql
select employee_id from org_tree where level between 1 and 3
```

就可以得到本题的结果。

PS: 查了一下， MySQL 8.x 中已经引入了「递归CTE」语法  ＼(￣▽￣)／