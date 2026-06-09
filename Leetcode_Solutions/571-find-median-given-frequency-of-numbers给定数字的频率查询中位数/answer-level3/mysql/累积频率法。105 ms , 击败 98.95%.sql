### 解题思路
偶数取均值，奇数取一个值。
### 代码

```mysql
# Write your MySQL query statement below
select avg(number) as median
from 
    (
        select 
            number,
            @cumFrequency :=@cumFrequency+frequency as cumFrequency,
            frequency 
        from (select * from numbers order by number)r, (select  @cumFrequency:=0)t3
    )t1,
    (
        select   sum(frequency)/2  as num,MOD(sum(frequency),2) AS doubles
        from Numbers
    )t2
    
where doubles= 0 AND NUM >=(cumFrequency-frequency) and NUM<=cumFrequency 
    or doubles = 1 AND NUM > (cumFrequency-frequency) and NUM<=cumFrequency 
 
```