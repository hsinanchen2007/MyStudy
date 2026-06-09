### 解法一：使用left join
思路：

分别给美洲、亚洲、欧洲的学生按照学生姓名排序编号。

然后将三个洲的学生根据排序编号关联起来，目的是为了将同一编号的美洲、亚洲、欧洲的学生被连在一起。

最后按序输出美洲、亚洲、欧洲的所有学生姓名即可。
```
select America,Asia,Europe 
from(
    select row_number() over(order by name) as rn,name as America from student
    where continent='America'
) a
left join(
    select row_number() over(order by name) as rn,name as Asia from student
    where continent='Asia'
) b on a.rn=b.rn
left join(
    select row_number() over(order by name) as rn,name as Europe from student
    where continent='Europe'
) c on a.rn=c.rn
```
执行用时 :718 ms, 内存消耗 :0B

### 解法二：使用case when ...（参考其他大神的解法）
思路：

同样先是根据洲名分组，对同一洲名的学生进行组内排序编号；

然后分别判断这些学生的所属洲：
如果是美洲，则将该学生的名字赋值给美洲，否则置null；
如果是亚洲，则将该学生的名字赋值给亚洲，否则置null；
如果是欧洲，则将该学生的名字赋值给欧洲，否则置null；

到这一步，就已经实现了列转行。下面需要将列转行的结果根据编号整合一下。

最后将这些记录根据排序的编号分组，分别取美洲、亚洲、欧洲栏位的最大值，这样就可以将同一编号的学生放在一起，同时又过滤掉多余null的情况。
```
select
     max(case when continent='America' then name else null end) as America
    ,max(case when continent='Asia' then name else null end) as Asia
    ,max(case when continent='Europe' then name else null end) as Europe
from(
    select row_number() over(partition by continent order by name) as rn,* from student
) t
group by rn
```
执行用时 :652 ms, 内存消耗 :0B
