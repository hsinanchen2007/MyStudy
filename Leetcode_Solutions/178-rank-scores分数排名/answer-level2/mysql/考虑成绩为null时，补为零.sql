**在分数为null时，处理为0**
有两种解法：

```mysql
-- 方法1
select ifnull(a.score, 0) as score,
       (select count(DISTINCT b.score) from source b where ifnull(a.score, 0) <= ifnull(b.score, 0)) as `rank`
from source a
order by a.score DESC;
```
> 使用子查询


```mysql
-- 方法2
SELECT
  ifnull(a.score, 0) as score,
  COUNT(DISTINCT b.score) AS `Rank`
FROM
  source a,
  source b
WHERE ifnull(b.score, 0) >= ifnull(a.score, 0)
GROUP BY a.id
ORDER BY a.score DESC
```
> 使用联结，通过where语句限定联结，如果成绩过多的时候，where语句联结的数据就会过多，不推荐使用