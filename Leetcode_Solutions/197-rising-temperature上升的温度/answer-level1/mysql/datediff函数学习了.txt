题目较简单，思路是将两个表联合然后同一列两个temperature进行大小比较
之前利用id相减进行联合：1.没有考虑到日期不是按顺序排 2.只有两个数据的时侯会出现差错
今日打卡over
mysql datadiff只有两个参数，而sqlserver是三个，再次掉坑
```
# Write your MySQL query statement below
select d1.id as 'Id'
from weather d1 join weather d2 ON DATEDIFF(d1.RecordDate, d2.RecordDate) = 1
where d1. Temperature>d2. Temperature
```
