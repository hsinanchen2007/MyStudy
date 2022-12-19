### 解题思路
此处撰写解题思路
TIMESTAMPDIFF函数
### 代码

```mysql
# Write your MySQL query statement below
select w1.Id
from Weather as w1, Weather as w2
where TIMESTAMPDIFF(DAY, w2.RecordDate, w1.RecordDate) = 1 AND w1.Temperature > w2.Temperature

```