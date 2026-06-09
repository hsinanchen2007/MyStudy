这道题主要是在函数的应用上，没有什么特别特俗的语法，oracle比mysql这个题跑得慢了
```
SELECT *
FROM (
	SELECT a.team_id, MAX(team_name) AS team_name, SUM(CASE 
			WHEN a.team_id = b.host_team THEN 
				CASE 
					WHEN b.host_goals > b.guest_goals THEN 3
					WHEN b.host_goals = b.guest_goals THEN 1
					ELSE 0
				END
			WHEN a.team_id = b.guest_team THEN 
				CASE 
					WHEN b.host_goals < b.guest_goals THEN 3
					WHEN b.host_goals = b.guest_goals THEN 1
					ELSE 0
				END
			ELSE 0
		END) AS num_points
	FROM Teams a
		LEFT JOIN Matches b
		ON a.team_id = b.host_team
			OR a.team_id = b.guest_team
	GROUP BY a.team_id
) a 
ORDER BY a.num_points DESC,a.team_id
```
