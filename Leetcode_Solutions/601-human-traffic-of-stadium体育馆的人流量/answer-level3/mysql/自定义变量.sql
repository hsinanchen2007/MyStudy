### 解题思路
跟作者“北斗”一个方法，但他的题解更加优秀

### 代码

```mysql
# Write your MySQL query statement below
select * from stadium where id in
(
    select id-2 from
    (
        select id ,if(people>99,@rank:=@rank+1,@rank:=0) as rank
        from stadium,(select @rank :=0)a
    ) p1 
    where rank >2
    union all 
    select id-1 from
    (
        select id ,if(people>99,@rank:=@rank+1,@rank:=0) as rank
        from stadium,(select @rank :=0)a
    ) p1 
    where rank >2
        union all 
    select id  from
    (
        select id ,if(people>99,@rank:=@rank+1,@rank:=0) as rank
        from stadium,(select @rank :=0)a
    ) p1 
    where rank >2
)

```