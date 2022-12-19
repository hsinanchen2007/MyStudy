### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below


select Name from Candidate
where id=
(select CandidateId from Vote
group by CandidateId having count(CandidateId)=
(select max(total_count) from (select count(CandidateId) as total_count from 
Vote group by CandidateId) tmp))
```