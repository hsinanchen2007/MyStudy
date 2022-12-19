#注意，重复的记录视作两个不同的人，要想保留重复记录，只能row_rank()排序
#思路：组内排序，再按照排名分组，并利用case when建立新列
/*
#以下两种均错误：下面的排序只能实现dense_rank()组内排序，去掉distinct只能实现rank()组内排序
##自连接实现组内dense_rank()排序
select
max(case when continent="America" then name else null end) America,
max(case when continent="Asia" then name else null end) Asia,
max(case when continent="Europe" then name else null end) Europe
from
(select s1.name,s1.continent,count(distinct s2.name)+1 row_number
from student s1 left join student s2
on s1.continent=s2.continent and s2.name<s1.name
group by s1.name,s1.continent) t1
group by row_number
*/
/*
#计算型子查询实现dense_rank()排序
select
max(case when continent="America" then name else null end) America,
max(case when continent="Asia" then name else null end) Asia,
max(case when continent="Europe" then name else null end) Europe
from
(select s1.name,s1.continent,(select count(distinct s2.name)+1 from student s2 where s2.continent=s1.continent and s2.name<s1.name) row_number
from student s1)t1
group by row_number
*/
/*
#窗口函数row_number排序
select
    max(case when continent = 'America' then name else null end) America,
    max(case when continent = 'Asia' then name else null end) Asia,
    max(case when continent = 'Europe' then name else null end) Europe
from
    (select 
        name, 
        continent, 
        row_number()over(partition by continent order by name) cur_rank
    from
        student)t 
group by cur_rank
*/

#正确解法(1)：
#见讨论区 id 旺仔QQ糖
#使用变量实现row_number排序,注意order by执行顺序与sql差异！！
/*
select 
max(case continent when 'America' then name else null end) America,
max(case continent when 'Asia' then name else null end) Asia,
max(case continent when 'Europe' then name else null end) Europe
from
(select name,continent,
if(@tmp=continent,@rownum:=@rownum+1,@rownum:=1) as rnk,@tmp:=continent from student s1,(select @tmp:=0,@rownum:=1) r1
order by continent,name asc) t
group by rnk
*/
#正确解法（2）变量实现row_number排序，以及有大坑：关于order by的子查询是否执行！！
select 
max(case continent when 'America' then name else null end) America,
max(case continent when 'Asia' then name else null end) Asia,
max(case continent when 'Europe' then name else null end) Europe
from
(select name,continent,
case when @continent=continent then @row_number:=@row_number+1 else @row_number:=1 end row_number,@continent:=continent new_continent
from (select * from student order by continent,name limit 100000)t1,(select @continent:=0,@row_number:=0)t2)t3
group by row_number
#注意：（1）mysql于sql执行顺序有不同！！（2）mysql 子查询不可仅仅含order by （3）mysql limit语句不可存在与in/all/any/some子查询中