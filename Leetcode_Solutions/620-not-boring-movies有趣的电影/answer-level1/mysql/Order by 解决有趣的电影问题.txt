### 解题思路
首先使用where语句筛选除非broing且id为奇数的人，然后使用order by进行降序排序

### 代码

```mysql
# Write your MySQL query statement below
select * from cinema
where description != 'boring' and id %2 !=0
order by rating DESC
```