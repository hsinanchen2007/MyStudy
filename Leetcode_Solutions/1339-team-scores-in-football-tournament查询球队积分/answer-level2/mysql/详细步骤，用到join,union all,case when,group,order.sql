首先:将host与guest分别提取用onion all连接（x允许有重复值）
SELECT host_team as team_id ,host_goals as goals1,guest_goals as goals2
FROM Matches
UNION ALL
SELECT guest_team as team_id,guest_goals as goals1,host_goals as goals2
FROM Matches

接着:根据比分情况求和
SELECT team_id,SUM(CASE WHEN goals1 > goals2 THEN 3 WHEN goals1 = goals2 THEN 1 ELSE 0 END) as num_points
FROM
(SELECT host_team as team_id ,host_goals as goals1,guest_goals as goals2
FROM Matches
UNION ALL
SELECT guest_team as team_id,guest_goals as goals1,host_goals as goals2
FROM Matches) AS temp

最后:利有JOIN获取队伍名字，注意有的队伍为0
SELECT Teams.team_id,Teams.team_name,SUM(CASE WHEN goals1 > goals2 THEN 3 WHEN goals1 = goals2 THEN 1 ELSE 0 END) as num_points
FROM
(SELECT host_team as team_id ,host_goals as goals1,guest_goals as goals2
FROM Matches
UNION ALL
SELECT guest_team as team_id,guest_goals as goals1,host_goals as goals2
FROM Matches) AS temp RIGHT JOIN Teams
ON temp.team_id=Teams.team_id
GROUP BY team_id
ORDER BY num_points DESC,team_id

