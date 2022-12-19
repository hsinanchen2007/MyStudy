```
/* Write your PL/SQL query statement below */
select seat_id
from (
        select tmp.*,count(*) over(partition by x )  y
        from (
            -- 连续相同值
            select c.*,rownum-row_number() over(partition by free order by rownum) x
                from cinema c) tmp
        -- 筛选空座位
        where free=1)
where y>=2
order by seat_id;








```
