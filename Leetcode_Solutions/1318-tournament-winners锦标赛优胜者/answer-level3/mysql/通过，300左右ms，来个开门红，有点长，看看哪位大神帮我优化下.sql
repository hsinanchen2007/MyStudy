# Write your MySQL query statement below

SELECT t.group_id, t.player_id

FROM
(SELECT p1.group_id, t4.scores, MIN(t4.player_id) AS player_id
FROM
 (SELECT t3.player_id, SUM(t3.score) AS scores
FROM
    ((SELECT first_player AS player_id, SUM(first_score) AS score
FROM Matches
GROUP BY first_player)
UNION ALL
(SELECT second_player AS player_id, SUM(second_score) AS score
FROM Matches
GROUP BY second_player)) AS t3

GROUP BY t3.player_id) AS t4
INNER JOIN Players AS p1
ON t4.player_id=p1.player_id
GROUP BY p1.group_id, t4.scores) AS t

WHERE (t.group_id, t.scores) IN 
(
SELECT p.group_id, MAX(t2.scores)
FROM
(SELECT player_id, SUM(score) AS scores
FROM
((SELECT first_player AS player_id, SUM(first_score) AS score
FROM Matches
GROUP BY first_player)
UNION ALL
(SELECT second_player AS player_id, SUM(second_score) AS score
FROM Matches
GROUP BY second_player)) AS t1
GROUP BY player_id) AS t2
INNER JOIN
Players AS p 
ON t2.player_id=p.player_id
GROUP BY p.group_id
)





```
代码块
```
