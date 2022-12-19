### 解题思路
有没有简便方法啊

### 代码

```mysql
select
    c.Name
from
    Candidate                                                                                                               c
        join( select
                  CandidateId
              from
                      ( select CandidateId, count(*) cnt from Vote v group by CandidateId ) tmp2
              where
                      tmp2.cnt = ( select max(tmp1.cnt)
                                   from
                                           ( select CandidateId, count(*) cnt from Vote v group by CandidateId ) tmp1 ) ) tmp3
            on c.id = tmp3.CandidateId



```