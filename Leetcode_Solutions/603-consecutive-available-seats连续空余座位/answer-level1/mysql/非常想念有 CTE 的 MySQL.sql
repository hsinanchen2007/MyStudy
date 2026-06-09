遇到这种根据连续多条记录的关系进行判断的题目，第一反应就是用自定义变量给每行记录打上标记：

```sql
select t1.seat_id, if(t1.free = 0, @cnt := 0, @cnt := @cnt + 1) as cnt
from cinema t1,
     (select @cnt := 0 from dual) t2
```
得到结果：

| seat\_id | cnt |
| :--- | :--- |
| 1 | 1 |
| 2 | 0 |
| 3 | 1 |
| 4 | 2 |
| 5 | 3 |

根据题目，大于两个以上的连续记录是我们想要的：
```sql
select t1.seat_id
from (
         select t1.seat_id, if(t1.free = 0, @cnt := 0, @cnt := @cnt + 1) as cnt
         from cinema t1,
              (select @cnt := 0 from dual) t2
     ) t1
where t1.cnt > 1;
```

| seat\_id |
| :--- |
| 4 |
| 5 |

嗯，似乎还缺了点什么。连续记录点第一条也应该包含在内，我们可以再关联一下 cinema
```sql
select t2.seat_id
from (
         select t1.seat_id, if(t1.free = 0, @cnt := 0, @cnt := @cnt + 1) as cnt
         from cinema t1,
              (select @cnt := 0 from dual) t2
     ) t1 inner join cinema t2 on t1.seat_id = t2.seat_id + 1
where t1.cnt > 1;
```

抑或者直接对 seat_id 减一：
```sql
select t1.seat_id - 1
from (
         select t1.seat_id, if(t1.free = 0, @cnt := 0, @cnt := @cnt + 1) as cnt
         from cinema t1,
              (select @cnt := 0 from dual) t2
     ) t1
where t1.cnt > 1;
```
 
得到：
| seat\_id |
| :--- |
| 3 |
| 4 |

最后，将表 2 和表 3 的结果合并，使用 union 而不是 union all ，对结果去重。
```sql
select t1.seat_id
from (
         select t1.seat_id, if(t1.free = 0, @cnt1 := 0, @cnt1 := @cnt1 + 1) as cnt
         from cinema t1,
              (select @cnt1 := 0 from dual) t2
     ) t1
where t1.cnt > 1
union
select t1.seat_id - 1
from (
         select t1.seat_id, if(t1.free = 0, @cnt2 := 0, @cnt2 := @cnt2 + 1) as cnt
         from cinema t1,
              (select @cnt2 := 0 from dual) t2
     ) t1
where t1.cnt > 1
order by 1
```

以上。