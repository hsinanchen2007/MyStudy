![图片.png](https://pic.leetcode-cn.com/65d4c36ff00c7d1ef508ec3b8ce9fed86ac0e2746dc0b300ebe9c15e7d4fff1e-%E5%9B%BE%E7%89%87.png)

```
select p.FirstName,p.LastName,a.City,a.State from Person as p left join Address as a on p.PersonId=a.PersonId;
```
