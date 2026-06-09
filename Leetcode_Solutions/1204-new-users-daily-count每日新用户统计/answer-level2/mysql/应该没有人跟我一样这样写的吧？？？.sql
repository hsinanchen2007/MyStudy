select login_date ,count(*) as user_count from 
(select min(activity_date) as login_date , user_id as user_count from Traffic
 where datediff('2019-06-30',activity_date)<=90 and activity='login'
and user_id not in (select user_id from Traffic where datediff('2019-06-30',activity_date)>90 
and activity='login')
group by user_id) 
as t group by login_date