### 解题思路
`首先分析两个表的关系，Person表中的PersonId是Address表中的**外键**，那么可以考虑用连接来关联查询，因为Address可能不是每个人都有，那么可以选择**LEFT JOIN**查询。`

### 代码

```mysql
Select p.FirstName,p.LastName,a.City,a.State From Person p LEFT JOIN Address a ON p.PersonId = a.PersonId
```