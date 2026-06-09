/* Write your T-SQL query statement below */
select round(convert(float,count(activity.event_date))/convert(float,count(a.player_id)),2) as fraction
from
(select distinct player_id,min(event_date)
from activity
group by player_id) as a(player_id,min_date)
left join activity
on activity.player_id = a.player_id
and dateadd(day,1,a.min_date) = activity.event_date
