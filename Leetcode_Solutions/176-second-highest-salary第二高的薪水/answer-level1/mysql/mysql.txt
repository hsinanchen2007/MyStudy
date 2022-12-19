![图片.png](https://pic.leetcode-cn.com/5ad80cddf3d3959d4b668846d7fd828158757bbf2c59d3140e41144efafc8405-%E5%9B%BE%E7%89%87.png)

```
select max(Salary) as SecondHighestSalary from Employee where Salary<(select max(Salary) from Employee);
```
