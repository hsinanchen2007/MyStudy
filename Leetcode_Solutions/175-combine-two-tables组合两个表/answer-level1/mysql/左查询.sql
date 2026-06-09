### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select P.FirstName,P.lastName,A.city,A.State from Person P left join ADDress A on P.PersonId  = A.PersonId;
```