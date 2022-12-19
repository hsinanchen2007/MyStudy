![图片.png](https://pic.leetcode-cn.com/6412c69a06a33507a0f7beabcc791927de67d9cc13663f23dd37ffae119f22cb-%E5%9B%BE%E7%89%87.png)

```
select a.Name as Employee from Employee as a join Employee as b on a.ManagerId=b.Id and a.Salary>b.Salary;
```
