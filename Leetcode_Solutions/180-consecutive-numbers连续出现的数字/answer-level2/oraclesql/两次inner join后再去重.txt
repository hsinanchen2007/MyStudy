/* Write your PL/SQL query statement below */
select consecutivenums from
(
select t11.num consecutivenums from
(
select t.id,t.num from logs t
join
(select id-1 as id,num from logs) tp1
on t.id=tp1.id and t.num=tp1.num
) t11
join
(select id-2 as id,num from logs) t2
on t11.id=t2.id and t11.num=t2.num
    ) group by consecutivenums