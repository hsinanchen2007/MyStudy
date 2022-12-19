/* Write your PL/SQL query statement below */

/*
用开窗函数去生成连续的序列号，防止id不连续的情况。
用这种三张表去连接的方式然后连接条件中还要带运算符的写法特别不好，
使用运算符之后索引就失效了表之间连接的效率变得特别低。
*/
'''
select distinct l1.num as ConsecutiveNums 
from
 (select num, row_number() over(order by id) rank_num from logs) l1,
 (select num, row_number() over(order by id) rank_num from logs) l2,
 (select num, row_number() over(order by id) rank_num from logs) l3
where 1 = 1
and l1.rank_num = l2.rank_num-1
and l1.rank_num = l3.rank_num-2
AND l1.num = l2.num
AND l1.num = l3.num;
'''

