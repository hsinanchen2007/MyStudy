### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select name as activity  from Activities
where name not in 
(select f.activity from Friends f inner join 
Activities a on 
f.activity=a.name
group by f.activity having count(f.activity)=(select count(f.activity) from Friends f inner join 
Activities a on 
f.activity=a.name
group by f.activity
order by count(f.activity) desc
limit 1)
) 
and name not in
(select f.activity from Friends f inner join 
Activities a on 
f.activity=a.name
group by f.activity having count(f.activity)=(select count(f.activity) from Friends f inner join 
Activities a on 
f.activity=a.name
group by f.activity
order by count(f.activity) asc
limit 1)
)
```