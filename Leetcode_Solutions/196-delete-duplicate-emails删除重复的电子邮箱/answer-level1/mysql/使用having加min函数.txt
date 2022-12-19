1、查询出Email出现次数大于1次的Email以及对应的最小Id,也就是min函数
select Email,MIN(Id) Id
            from Person 
            group by Email
            having count(Email) > 1 
2、然后以Email为条件且过滤掉最小Id【min(Id)】的数据
select p.Id
    from (
        select Email,MIN(Id) Id
            from Person 
            group by Email
            having count(Email) > 1 
    ) as s 
	left join Person p on p.Email = s.Email
	where p.Id > s.Id 
3、最后封装一次，加入到delete语句中：

delete from Person where Id in (
select a.Id 
from (
select p.Id
    from (
        select Email,MIN(Id) Id
            from Person 
            group by Email
            having count(Email) > 1 
    ) as s 
	left join Person p on p.Email = s.Email
	where p.Id > s.Id 
) as a 
);
