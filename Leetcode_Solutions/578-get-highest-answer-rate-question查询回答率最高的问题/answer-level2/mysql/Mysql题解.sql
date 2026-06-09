select question_id survey_log
from survey_log
group by question_id
order by sum(if(action="answer",1,0))/sum(if(action="show",1,0)) desc limit 1