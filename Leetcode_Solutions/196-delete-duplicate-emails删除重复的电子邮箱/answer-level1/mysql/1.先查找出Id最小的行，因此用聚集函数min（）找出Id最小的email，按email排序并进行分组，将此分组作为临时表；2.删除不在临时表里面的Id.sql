### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
Delete From Person
Where Not Id In (Select Id
From (Select Min(Id) as ID
From Person
group by Email) as Temp)
```