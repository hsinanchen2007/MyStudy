### 解题思路
对于从自身删除重复值的情况，可以做自身和自身的`INNER JOIN`，然后根据条件找出要删除的数据就行了

### 代码

```mysql
# Write your MySQL query statement below

DELETE t1 FROM Person as t1
INNER JOIN Person as t2
WHERE t1.Id > t2.Id and t1.Email = t2.Email
```