简单的sql题比简单的算法题好做多了....

### 代码

```mysql
select a.Email from
(select Email,count(Email) as count from Person group by Email) a
where a.count>1
```