select A.name activity
from Activities A left join Friends F
on A.name=F.activity
group by A.name
having count(*)<(select count(id) from Friends group by activity order by count(*) desc limit 1)
and count(*)>(select count(id) from Friends group by activity order by count(*) limit 1)