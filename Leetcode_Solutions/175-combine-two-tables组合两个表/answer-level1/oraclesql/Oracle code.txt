Oracle 解法：

```
select FirstName, LastName, City, State 
    from Person p,Address a
    where p.PersonId=a.PersonId(+);
```
[组合两个表](https://leetcode-cn.com/problems/combine-two-tables)