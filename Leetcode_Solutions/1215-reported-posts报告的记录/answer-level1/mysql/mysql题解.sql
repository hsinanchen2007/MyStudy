select extra report_reason,count(distinct post_id)report_count
from Actions
where datediff("2019-07-05",action_date)=1 and extra is not null and action="report"
group by extra