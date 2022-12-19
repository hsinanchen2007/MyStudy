### 解题思路
一开始没注意那个坑，以为就是这么简单。。。

### 代码

```mysql
select a.class
from
    (select class,count(distinct student) as num
    from courses
    group by class) a
where a.num>=5;
```