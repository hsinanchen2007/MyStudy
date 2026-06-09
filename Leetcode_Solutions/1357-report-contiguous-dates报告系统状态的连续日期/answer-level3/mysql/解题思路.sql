### 解题思路
1.两部分数据并起来
2.按日期排序后遍历，分配group_id,连续成功或失败group_id一致
3.按group_id分组，取最大和最小日期即为end_date、start_date

### 代码

```mysql
# Write your MySQL query statement below

SELECT if(task_result = 0, 'failed', 'succeeded') AS period_state
	, MIN(date) AS start_date, MAX(date) AS end_date
FROM (
	SELECT date, task_result
		, @group_id := if(@last_result = task_result, @group_id, @group_id + 1) AS group_id
		, @last_result := task_result
	FROM (
		SELECT fail_date AS date, 0 AS task_result
		FROM Failed
		UNION
		SELECT success_date AS date, 1 AS task_result
		FROM Succeeded
	) a, (
			SELECT @group_id := 0, @last_result := 0
		) temp
	WHERE date BETWEEN '2019-01-01' AND '2019-12-31'
	ORDER BY date ASC
) b
GROUP BY group_id
ORDER BY start_date ASC
```