### 解题思路
题目中说的高峰期是连续三天，每天人流量超过100。对于高峰期的每一天，有这样的特点：其人流量必然都不小于100，且必然符合以下三个条件中的任意一个：
1、它之前连续的两天人流量都不小于100；
2、它的前一天和后一天的人流量都不小于100；
3、它的后面连续两天人流量都不小于100.

思路理清楚了，下面就是实现的方法。这题如果采用Oracle的分析函数lead()和lag()+窗口函数over()，是比较简单的，就不贴代码了。这里主要给出不采用特定分析函数的通用方法。

下面的代码可在oracle中运行，没有使用lead()和lag()分析函数。将日期格式转换函数to_char()改成DATA_FORMAT()，这段代码就可以在mysql中运行。

另外，题目中可能默认ID是连续的（很多人也是按照这个前提来写代码），但实际项目中，ID并不一定连续，因此我这个SQL是在默认ID是可以不连续的前提下写的，采用一个子查询来得到前一条记录或后一条记录（也即前一天或后一天）。将条件中的ID字段全部替换成visit_date，也是成立的。

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select id "id",to_char(visit_date,'yyyy-mm-dd') "visit_date",people "people"
from   stadium t
where  t.people >= 100
and  ((exists (
  select people
  from   stadium t2
  where  t2.id = (SELECT MAX(t22.id) FROM stadium t22 WHERE t22.id < t.id)
  and    t2.people >= 100
) and  exists (
  select null
  from   stadium t3
  where  t3.id = (SELECT MAX(t33.id) FROM stadium t33 WHERE t33.id < 
                             (SELECT MAX(t22.id) FROM stadium t22 WHERE t22.id < t.id))
  and    t3.people >= 100
)
) or (exists (
  select people
  from   stadium t2
  where  t2.id = (SELECT MIN(t22.id) FROM stadium t22 WHERE t22.id > t.id)
  and    t2.people >= 100
) and  exists (
  select null
  from   stadium t3
  where  t3.id = (SELECT MIN(t33.id) FROM stadium t33 WHERE t33.id > 
                             (SELECT MIN(t22.id) FROM stadium t22 WHERE t22.id > t.id))
  and    t3.people >= 100
)
) or (exists (
  select people
  from   stadium t2
  where  t2.id = (SELECT MAX(t22.id) FROM stadium t22 WHERE t22.id < t.id)
  and    t2.people >= 100
) and  exists (
  select null
  from   stadium t3
  where  t3.id = (SELECT MIN(t22.id) FROM stadium t22 WHERE t22.id > t.id)
  and    t3.people >= 100
)
))
```