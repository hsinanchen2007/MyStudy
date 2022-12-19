### 解题思路
此处撰写解题思路
先按日期连表，然后查出温度符合条件的id
### 代码

```mysql
# Write your MySQL query statement below
select w1.Id from Weather w1 left join Weather w2 on dateDiff(w1.RecordDate,w2.RecordDate)=1 where w1.Temperature > w2.Temperature
```