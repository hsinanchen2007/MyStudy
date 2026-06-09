可以 count(answer_id)

```
select question_id survey_log from survey_log
group by question_id
order by count(answer_id)/count(action) desc
limit 1

```
为什么不能 count(if(action='answer',1,0)) ?
```
select question_id survey_log from survey_log
group by question_id
order by count(answer_id)/count(action) desc
limit 1

```
