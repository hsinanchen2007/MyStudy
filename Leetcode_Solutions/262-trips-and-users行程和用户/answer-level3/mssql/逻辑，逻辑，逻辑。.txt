### 解题思路
非禁止用户的取消率=非禁止用户取消的订单数/非禁止用户生成的订单总数
第一步：
连接日期与订单状态，生成非禁止用户订单状态表
select t.request_at,t.status from trips t,users u
where t.client_id=u.users_id
and u.banned='No';
第二步：
从非禁止用户订单状态表中，统计每个日期中被取消的订单数，总订单数
将第一步中生成的临时表命名为temp，从temp中统计每个日期被取消的订单数、每个日期的总订单数：
#每个日期被取消的订单数：
使用case when 循环语句
select temp.request_at,sum(case temp.status when 'Completed' then 0 else 1) from temp group by temp.request_at
#每个日期的总订单数
select temp.request_at,count(temp.status) from temp group by temp.request_at
得到的上述两个日期，相除既可得到要求的数据
第三步：将上述语句整合，并按照要求命名
select temp.request_at Day,
round(sum(case temp.status when 'Completed' then 0 else 1)/count(temp.status),2) 'Cancellation Rate'
from
(select t.request_at,t.status from trips t,users u
where t.client_id=u.users_id
and u.banned='No') as temp
where temp.request_at between '2010-13-01' and '2013-10-03'
group by temp.request;

###几个注意点：
1.生成一个非禁止用户，订单完成状态的临时表（日期、订单状态两列）需要的非禁止用户订单数量计算、订单取消数量计算都可在此表基础上生成
2.case when 循环语句一定要有end关键字
3.计算取消率的时候，用round()函数，设置要保留的小数位数
4.要求查找‘2013年10月1日 至 2013年10月3日 期间非禁止用户的取消率’用between and语句，为日期设置范围

### 代码

```mysql
# Write your MySQL query statement below
select temp.request_at Day,
round(sum(case temp.status when 'Completed' then 0 else 1 end)/count(temp.status),2) 'Cancellation Rate'
from
(select t.request_at,t.status from trips t,users u
where t.client_id=u.users_id
and u.banned='No') as temp
where temp.request_at between '2013-10-01' and '2013-10-03'
group by temp.request;

```