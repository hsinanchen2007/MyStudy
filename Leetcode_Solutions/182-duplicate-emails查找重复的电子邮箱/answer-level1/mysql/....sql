### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select Email from person
group by email
having count(Email)>1
```