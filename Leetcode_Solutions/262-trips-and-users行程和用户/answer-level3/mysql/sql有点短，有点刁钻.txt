执行用时 :155 ms, 在所有 MySQL 提交中击败了64.80%的用户
这题竟然归为困难级别，实在有些不符

### 解题思路
* 题目中只说了总数为非禁止用户生成的订单，订单肯定是Client发起的，貌似可以理解成只要限制Client_Id是否禁用即可
* 统计被取消的，而题目指明Status只有三种状态，故直接判断t.Status != 'completed'
剩下的就是简单的inner join, group by，sum，count啥的了

### 代码

```mysql
# Write your MySQL query statement below
select t.Request_at 'Day', ROUND(sum(t.Status != 'completed')/count(1),2) 'Cancellation Rate'
from Trips t
inner join Users c on t.Client_Id = c.Users_Id and c.Banned = 'No'
where t.Request_at between "2013-10-01" and "2013-10-03"
group by t.Request_at
```