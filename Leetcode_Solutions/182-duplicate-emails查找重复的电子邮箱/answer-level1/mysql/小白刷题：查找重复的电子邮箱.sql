group by分组，having筛选，count(*)计数，大于1就是重复

代码：
```
select email from person
group by email
having count(*) > 1
```
