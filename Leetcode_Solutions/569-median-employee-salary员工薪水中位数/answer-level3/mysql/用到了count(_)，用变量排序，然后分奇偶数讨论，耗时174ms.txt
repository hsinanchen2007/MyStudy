先得到每个公司的人数,然后按照(公司,薪水)增序排列,同时用变量得到他们的排名rank,然后分情况讨论,如果长度为n,奇数的判断
(n + 1) / 2 =  rank ,偶数的判断 cnt / 2 = rank or cnt / 2 = rank - 1,最后得到结果再按照(公司,薪水)增序排列
```
select t2.Id,t2.Company,t2.Salary from
(select t1.Id,t1.Company,t1.Salary,
(
    case when t1.cnt % 2 = 1 and (t1.cnt + 1) / 2 = t1.rank then 'median'
         when t1.cnt % 2 = 0 and 
         (t1.cnt / 2 = t1.rank or t1.cnt / 2 = t1.rank - 1) then 'median'
         else 'other' end
) as flag
from
(select e.*,cast(if(@prev = e.Company,@rank := @rank + 1,@rank := 1) as unsigned)  as rank,
@prev := e.Company as prev,t.cnt
from Employee e,
(select Company,count(*) as cnt
from Employee
group by Company) as t,
(select @prev := null,@rank := 0 ) as init
where e.Company = t.Company
order by Company,Salary) as t1) as t2
where t2.flag = 'median'
order by t2.Company,t2.Salary
```

![WechatIMG140.jpeg](https://pic.leetcode-cn.com/891c5d33369a5f4e9ec80013c3483a06e3f2adac189a8dc59d523465d319d0fa-WechatIMG140.jpeg)
