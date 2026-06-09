### 解题思路
此处撰写解题思路
```
select  m.name  from (
select c.name,v.co   from Candidate c ,
(select  CandidateId, count(*) as co from Vote v group by CandidateId) v
where  c.id =v.CandidateId order by v.co desc limit 1
) m where 1=1
```

### 代码

```mysql
# Write your MySQL query statement below
select  m.name  from (
select c.name,v.co   from Candidate c ,
(select  CandidateId, count(*) as co from Vote v group by CandidateId) v
where  c.id =v.CandidateId order by v.co desc limit 1
) m where 1=1
-- select CandidateId, count(v.id) as co from Vote v group by CandidateId
```