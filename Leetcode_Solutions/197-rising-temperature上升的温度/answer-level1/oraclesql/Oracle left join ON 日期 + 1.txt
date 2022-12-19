> 执行用时: 908 ms, 在所有 Oracle 提交中击败了98.72%的用户

```sql
/* Write your PL/SQL query statement below */
select t2.Id as Id from    -- 这里一定是选择t2.Id
    Weather t1
left join 
    Weather t2
on t2.RecordDate = t1.RecordDate + 1
where t2.Temperature > t1.Temperature
```