### 解题思路
group by 后面加having count(*)会报错，但count(managerId)就对了
### 代码

173ms版本
```mysql
select name from employee WHERE id in
(select managerId from employee
 group by managerId
 having count(managerId)>4 
)
```

240ms
```mysql
# Write your MySQL query statement belo
select name from employee t2,
(select managerId,count(*) as num from employee
 group by managerId 
)t1
where  t2.id = t1.managerId and t1.num>4
