### 解题思路
这道题可以先不用管其他的，只需要先考虑取消率，每一天的取消率（PS：两端的都算），然后把两端的汇总除以每天的总数，保留小数点后两位，然后就酱紫了。。。。
### 代码

```mysql
# Write your MySQL query statement below

select t1.Request_at as `Day` , ROUND(SUM(CASE t1.`Status` WHEN 'cancelled_by_client' THEN 1 WHEN 'cancelled_by_driver' THEN 1 ELSE 0 END)/COUNT(t1.`Status`) ,2) as `Cancellation Rate` from Trips t1
join Users u1 on t1.Client_Id = u1.Users_Id and u1.Banned = 'No' 
join Users u2 on t1.Driver_Id = u2.Users_Id and u2.Banned = 'No'
where t1.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
group by t1.Request_at


```