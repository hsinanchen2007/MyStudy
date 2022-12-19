### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
#学习有空格的变量要加单引号
select Request_at as Day,round(sum(num)/count(*),2) as 'Cancellation Rate'
FROM
(
    select if(Status='completed',0,1) as num,Status,Request_at from trips
    where Client_Id   in
     (select Users_Id  from users where Banned = 'No' and Role='client')
     and Request_at between '2013-10-01' and '2013-10-03'
) t
group by Request_at

```