思路：

分为两部分：
1、仅有一次活动的用户，就输出这一次的活动；
2、有两次及两次以上活动的用户，将每个用户的活动按照开始日期倒序排序，取最后第二次的活动输出即可。
```
select username,activity,startDate,endDate 
from UserActivity 
where username in(
    select username from UserActivity
    group by username
    having count(activity)=1
)
union all
select username,activity,startDate,endDate 
from (
    select *,row_number() over(partition by username order by startDate desc) rn
    from UserActivity
) a
where rn=2
```
执行用时 :614 ms, 内存消耗 :0B