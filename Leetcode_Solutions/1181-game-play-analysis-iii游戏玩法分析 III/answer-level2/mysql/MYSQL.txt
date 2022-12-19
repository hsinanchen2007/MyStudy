SELECT A1.player_id AS player_id,A1.event_date AS event_date,
SUM(A2.games_played) AS games_played_so_far
FROM Activity A1 JOIN Activity A2
ON A1.player_id=A2.player_id
AND
A1.event_date>=A2.event_date
GROUP BY A1.player_id,A1.event_date;