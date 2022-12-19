### 解题思路
这个就是一个简单的左连接，用时多少全看测试用例，大家不用纠结时间

### 代码

```mysql
select p.FirstName, p.LastName, a.City, a.State from Person p left join  Address a on 
p.PersonId=a.PersonId
```
这个就是一个简单的左连接，用时多少全看测试用例，大家不用纠结时间
