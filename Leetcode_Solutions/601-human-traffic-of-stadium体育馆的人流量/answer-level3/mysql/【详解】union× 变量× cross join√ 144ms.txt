**首先小贴士：** 样例中把5-30日挖掉了，默认5-29与6-01为连续，因此需要使用id代替日期来思考本题。

**我们把问题转化一下：**
如果，我们可以获得每个日期下，都包含自己和下两日的人流量的表，那就可以简单通过where语句筛选出符合高峰期特征的日期。
并且，根据高峰期的特征，对于查询结果的某一天n，n+1与n+2这两天也是属于高峰期的。
**现在我们回到题目要求：**
输出所有高峰期内的日期。也就是，输出所有上一步我们讨论的日期，以及他们的后两天，并去重即可。
**具体步骤：**
1、自连接：通过双条件自连接获取'在每日下包含当日及之后两天的共三条人流记录'的表，并且要满足三条的人流的都大于100，并输出这一天。这里涉及到笛卡尔积的特性，忘记的可以百度复习一下，其中，
`between a.visit_date and a.visit_date+2`的条件确保了b.people仅输出当日即后两天的三条数据。

```
select a.visit_date from stadium a,stadium b
where b.visit_date between a.visit_date and a.visit_date+2 and b.people>=100
group by a.visit_date
having count(b.people)=3
```

2、第二次连接，获取第一步结果的当天及后两天日期，使用groupby去重。
```
select c.id,c.visit_date,c.people
from stadium c, (第一步骤结果) d
where c.id between d.id and d.id+2
group by c.id
```

**完整代码：**
```
select c.id,c.visit_date,c.people
from stadium c, 
    (select a.id from stadium a,stadium b where b.id between a.id 
    and a.id+2 and b.people>=100 group by a.visit_date having count(b.people)=3) d
where c.id between d.id and d.id+2
group by c.id
```

