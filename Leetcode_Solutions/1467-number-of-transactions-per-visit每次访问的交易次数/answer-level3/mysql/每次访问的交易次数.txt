### 解题思路
关键是要找到用户一次访问中的 max(transactions_count) ，然后从 0开始排序 。可以先求出最大访问次数的 user_id 和 transaction_date ，然后从Transactions 表找到相应的记录，此时根据条数可以求得排序。

### 代码

```mysql
# Write your MySQL query statement below

select G.transactions_count,ifnull(H.visits_count,0) visits_count 
from 
(

select 0  transactions_count 
union all
select  @j:=@j+1  transactions_count 
from Transactions W
inner join 
(
select user_id,transaction_date
from 
(
select  A.*,@i:=@i+1 l
from 
(
select  user_id,transaction_date,count(1) ct
from Transactions 
group by user_id,transaction_date 
) A
,(select @i:=0) B
order by ct desc
) K where K.l=1
) P
on W.user_id=P.user_id and W.transaction_date=P.transaction_date
,(select @j:=0) R

) G 
left join 

(

select T.ct,count(1) visits_count 
from 
(
select  A.user_id,A.visit_date,ifnull(B.ct,0) ct 
from Visits A
left join 
(
select user_id,transaction_date,count(1) ct
from Transactions 
group by user_id,transaction_date
) B on A.user_id=B.user_id and A.visit_date =B.transaction_date 
) T group by T.ct 

) H
on G.transactions_count=H.ct

```