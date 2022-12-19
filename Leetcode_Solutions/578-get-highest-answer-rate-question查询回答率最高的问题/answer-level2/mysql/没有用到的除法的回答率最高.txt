### 解题思路
题目真的不好读啊，其实回答率最高就是 answer 次数最多嘛。要注意 count(*) 与 count(列) 的区别是，列会不计 Null


### 代码

```mysql
# Write your MySQL query statement below

select question_id survey_log
from(
    select question_id,count(answer_id) cnt 
    from survey_log 
    group by question_id
) tmp1 
where tmp1.cnt =(
    select  max(cnt)
    from(
        select question_id,count(answer_id) cnt 
        from survey_log 
        group by question_id
    ) tmp2
)




```