首先，审题之后，我们发现**日期字段是干扰信息**，我们可以忽略它。

第一步，先将人流量大于等于100的记录过滤出来：
```
select id,visit_date,people,row_number() over(order by id) as rank from stadium where people>=100
```

第二步，先将可能的情况列出来，得到下面的表格：
![QQ图片20191130003741.png](https://pic.leetcode-cn.com/ec2682a6b7e19535978497d02c1e54e5ce398c23b5747d904a814dd6fc5f5f33-QQ%E5%9B%BE%E7%89%8720191130003741.png)



第三步，观察表格，可得知，id in (5,6,7,8)是我们所要的结果。这有什么规律呢，我们可以看到，**连续的记录，id-rank的值都是一样的，且每一段连续的数据，差值都不一样**，我们进一步加工数据：
```
select id,visit_date,people,id-row_number() over(order by id) as interval from stadium where people>=100
```
这样子得出来的数据如下：
![QQ图片20191130003854.png](https://pic.leetcode-cn.com/b4534421b919736702998cb70eb301dfda65e4bfa8a791796d2735c2fd80aa40-QQ%E5%9B%BE%E7%89%8720191130003854.png)


第四步，根据interval进行分组计算
```
select id,visit_date,people,count(interval) over(partition by interval) as count 
from
	(
		select id,visit_date,people,id-row_number() over(order by id) as interval
		from stadium where people>=100
	) t
```

第五步，得到最终需要的记录
```
select id,visit_date,people
from
(
	select id,visit_date,people,count(interval) over(partition by interval) as count 
	from
	(
		select id,visit_date,people,id-row_number() over(order by id) as interval
		from stadium where people>=100
	) t
) tt
where count>=3
```

这个解法，当题目要求有变化时，比如连续4天人流量不少于200，改动的地方只有2个数字，是为**最优雅的解法**

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/human-traffic-of-stadium
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
