### 解题思路
在一张表里做比较，首先想到复用。将两张表的数据做比较;
主表w1，附表w2.
可理解为w1的温度要比w2高，且w1是w2的后一天
select w1.id 
from weather w1,weather w2
where w1.temperature>w2.tepperature
and datediff(w1.recorddate,w2.recorddate)=1;
#注意：datediff()函数的使用方法，计算两个日期相隔天数

### 代码

```mysql
# Write your MySQL query statement below
select w1.id from weather w1,weather w2
where w1.temperature > w2.temperature
and datediff(w1.recorddate,w2.recorddate)=1;
```