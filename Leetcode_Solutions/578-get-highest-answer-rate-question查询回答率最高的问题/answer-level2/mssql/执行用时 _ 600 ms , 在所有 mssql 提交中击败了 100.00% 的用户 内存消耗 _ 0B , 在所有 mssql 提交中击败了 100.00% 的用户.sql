### 解题思路
按question_id分组后，分别计算answer的次数，除总出现次数，倒序排列后，取第一个即可

### 代码

```mssql
/* Write your T-SQL query statement below */
select top 1 question_id survey_log from
(select t1.question_id,isnull(qac,0)*1./qan rate from
(select question_id,count(answer_id) qac from survey_log where answer_id is not null group by question_id) t1
left join
(select question_id,count(question_id) qan from survey_log where answer_id is null group by question_id) t2
on t1.question_id = t2.question_id) t
order by rate desc
```