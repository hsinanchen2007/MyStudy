### 解题思路
和之前做的题很像，大致思路就是设计两个table然后合并，一个算approved，一个算total的

1. 算approve的数据，用where筛选，设为table a
2. 算total数据，设为table b
3. a right join table b


```mysql
# Write your MySQL query statement below
select b.month,b.country,trans_count,ifnull(approved_count,0) approved_count,
       trans_total_amount,ifnull(approved_total_amount,0) approved_total_amount
from (
select date_format(trans_date,'%Y-%m') month,country,count(state) approved_count,sum(amount) approved_total_amount
from transactions
where state = 'approved'
group by date_format(trans_date,'%Y-%m'),country
) a right join (
    select date_format(trans_date,'%Y-%m') month,country,count(state) trans_count,sum(amount) trans_total_amount
    from transactions
    group by date_format(trans_date,'%Y-%m'),country
) b on a.month = b.month and a.country = b.country







```