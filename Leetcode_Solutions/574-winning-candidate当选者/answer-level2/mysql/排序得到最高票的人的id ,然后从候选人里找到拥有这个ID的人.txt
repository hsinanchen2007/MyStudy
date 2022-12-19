### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select Name from Candidate
where id in
(
    select t.CandidateId from (select v.CandidateId
    from Vote v
    group by v.CandidateId
    order by count(*) desc
    limit 1)t
)
```