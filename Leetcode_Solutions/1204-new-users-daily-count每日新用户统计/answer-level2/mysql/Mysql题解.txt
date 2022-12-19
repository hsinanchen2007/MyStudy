select T.activity_date login_date,count(distinct T.user_id) user_count
from Traffic T
where T.activity_date=
(select min(activity_date) from Traffic where activity="login" and T.user_id=user_id)
and datediff("2019-06-30",T.activity_date)<=90
group by login_date