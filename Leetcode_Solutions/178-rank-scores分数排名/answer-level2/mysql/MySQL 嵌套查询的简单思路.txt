### 解题思路

分数排名，嵌套查询简单的思路如下：

1. 找出当前行 `s1.Score` 的排名
    - 查询比当前行 `s1.Score` 大的行数 `count`，并去重
    - 去重后的 `count` 即当前行分数的排名 `Rank`
    - 如题例 `3.85`
        - 比 `3.85` 大的行数为 `3` ( `3.85` , `4.00` , `4.00` ) ，去重后行数为 `2` ，`2` 即 `3.85` 的排名
2. 将 `Score` 以 `Rank` 升序

### 代码

```mysql
# Write your MySQL query statement below
SELECT Score,
       (SELECT COUNT(DISTINCT Score)
        FROM Scores s2
                WHERE s1.Score <= s2.Score) AS `Rank`
FROM Scores s1
ORDER BY `Rank`;
```