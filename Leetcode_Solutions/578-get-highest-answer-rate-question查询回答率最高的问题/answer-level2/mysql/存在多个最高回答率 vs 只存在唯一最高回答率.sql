# Write your MySQL query statement below
#组内操作，逻辑判断，最值选择
/*
#考虑存在多个相等答题率
select question_id survey_log
from
(select question_id,sum(action="answer")/count(*) ratio
from survey_log
group by question_id) t1
where ratio=(select max(ratio) from (select question_id,sum(action="answer")/count(*) ratio
from survey_log
group by question_id) t1)
*/

#只存在唯一最高
select question_id survey_log
from
(select question_id,sum(action="answer")/count(*) ratio
from survey_log
group by question_id)t1
order by ratio desc
limit 1