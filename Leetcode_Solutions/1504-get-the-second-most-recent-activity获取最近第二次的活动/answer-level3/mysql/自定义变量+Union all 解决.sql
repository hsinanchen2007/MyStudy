### 解题思路
自定义变量解决

### 代码

```mysql
# Write your MySQL query statement below
select username AS USERNAME,activity  as ACTIVITY,startDate AS STARTDATE,endDate AS ENDDATE from
(
    select u1.*,
    if(@name = username,@num := @num+1,@num := 1) as num,
    if(@name = username,username,@name := username) as name
    from (select * from UserActivity order by username,startDate desc) u1,(select @num := 0)p,(select @name := '')p1    
) t where num  = 2
union all
select u1.* from UserActivity u1 group by username having count(*) = 1 



```