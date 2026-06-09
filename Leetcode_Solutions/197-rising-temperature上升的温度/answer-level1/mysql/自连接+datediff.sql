### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select w.id from weather w,weather m where datediff(w.recorddate,m.recorddate)=1 and w.temperature>m.temperature;
```