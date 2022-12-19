
select question_id as survey_log 
from 
(
select question_id,answer_id
from survey_log
where answer_id is not null
) t1
  #筛选出answer_id 非空的 question_id 和 answer_id，新表就只有这两个字段
group by question_id             
  #按照question_id 分组
order by count(question_id) desc
  #分组后，按照question_id的总数进行计数，然后倒序排列
limit 1;                         
  #选出序列第一的值