### 解题思路1
先筛选 employee 条件查询 managerID出现次数大于4的经理编码 
然后查询以上筛选出来的经理名字

### 代码1

```oraclesql
/* Write your PL/SQL query statement below */
select a.name from employee a 
where a.id in
(select t.managerid managerid from employee t  
group by t.managerid 
having  count(t.managerid)>4)

```
### 解题思路2(效率小于解题思路一)
用连接 
### 代码2
select a.name from employee a,
(select t.managerid managerid from employee t  
group by t.managerid 
having  count(t.managerid)>4)b
where a.id=b.managerid