### 解题思路
这道题本身很简单，去重排序后用`limit`取第二高的就行了，或者用两次`max`。但是还是不太明白为什么题目要求：如果没有第二高的，应该返回`null`，而不是0条记录`[]`，有什么特殊含义吗？

### 代码

```mysql
# Write your MySQL query statement below
select (
    select distinct salary
    from Employee 
    order by Salary desc 
    limit 1 offset 1
    ) as SecondHighestSalary
```