找重复数据，首先使用 `group by `进行汇总，查看再使用` group by` 中的 过滤 having 进行过滤，使用`Count(字段) `进行统计汇总数据，大于1的则为重复。
其中 count 使用 当前汇总字段 比使用 * 要快，可能是因为 email中 使用索引，如果存在null值，* 不会使用到索引；




```
SELECT Email FROM Person 
GROUP BY Email
HAVING COUNT(Email) > 1
```