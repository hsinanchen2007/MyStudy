### 执行时间
143 ms

### 解题思路
1. 筛选所有超过100人的记录，按id递增排序
2. 遍历记录查看id连续性，增加一列minid用于表示本次连续记录最小id
3. 根据minid分组，取记录数大于2的分组
4. 使用GROUP_CONCAT函数取出分组内所有id，以,分割
5. 再次使用GROUP_CONCAT函数合并多个分组记录为一条，该条即包含所有符合条件记录id
6. 关联原始表，使用find_in_set函数取出所有记录详细信息

### 代码

```mysql
# Write your MySQL query statement below


SELECT sta.*
FROM stadium sta
	JOIN (
		SELECT GROUP_CONCAT(b.conc SEPARATOR ',') AS conc
		FROM (
			SELECT GROUP_CONCAT(id SEPARATOR ',') AS conc
			FROM (
				SELECT s.id
					, if(s.id=@lastid+1, @curr, @curr := s.id) AS minid
					, @lastid := s.id
				FROM (
					SELECT *
					FROM stadium
					WHERE people >= 100
				) s
					JOIN (
						SELECT @curr := '', @lastid := 0
					) temp
				ORDER BY s.id ASC
			) a
			GROUP BY minid
			HAVING COUNT(1) > 2
		) b
	) c
	ON find_in_set(sta.id, c.conc)
ORDER BY sta.id
```