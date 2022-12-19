### 解题思路
1. 获取关系：日期 - 总订单数
2. 获取关系：日期 - 取消订单数
3. 使用日期做自然连接，计算比例

### 代码
```oraclesql
/* Write your PL/SQL query statement below */
select s.Request_at Day, nvl(round(c.count/s.count,2),0) "Cancellation Rate"
from
(select t.Request_at, count(1) count
from Trips t, Users c, Users d
where t.Client_Id = c.Users_Id and c.Banned = 'No'-- 关联乘客
  and t.Driver_Id = d.Users_Id and d.Banned = 'No'-- 关联司机
  and t.Request_at between '2013-10-01' and '2013-10-03'--限制日期
group by t.Request_at) s--总订单
left join
(select t.Request_at, count(1) count
from Trips t, Users c, Users d
where t.Client_Id = c.Users_Id and c.Banned = 'No'-- 关联乘客
  and t.Driver_Id = d.Users_Id and d.Banned = 'No'-- 关联司机
  and t.Status != 'completed'
  and t.Request_at between '2013-10-01' and '2013-10-03'--限制日期
group by t.Request_at) c--取消订单
on c.Request_at = s.Request_at
order by Day
```

### 备注
1. 使用 nvl 来处理没有记录的日期（原理还不清楚）
2. 带空格的列别名需要使用双引号包围