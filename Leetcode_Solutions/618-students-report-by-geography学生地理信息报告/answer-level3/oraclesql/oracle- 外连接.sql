
题目中已说明美洲人数最多，因此美洲便成了基表，再运用外连接即可实现目标：

```sql
select
	america.name as america,
	asia.name as asia,
	europe.name as europe
from
	(select name, row_number() over(order by name) rn from student where continent = 'America') america
		left join (select name, row_number() over(order by name) rn from student where continent = 'Asia') asia on (america.rn = asia.rn)
		left join (select name, row_number() over(order by name) rn from student where continent = 'Europe') europe on (america.rn = europe.rn)

```

---

**进阶：** 如果不能确定哪个大洲的学生数最多，你可以写出一个查询去生成上述学生报告吗？

**答：** 如果不能确定哪个洲人数最多，则可以分为两步处理，第一步先找人数最多的洲，然后将人数最多的洲作为基表，再拼接出动态 SQL 即可。